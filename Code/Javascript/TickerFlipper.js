// TickerScrambler.js v0.1, Copyright (c) 2014 Lukasz Antkiewcz, MIT License
function TickerScrambler(element, options) {
    if (!element) return;
    if (element.nodeType != 1) return;
    if (!options) return;
    if (!options.list || !options.list.length) return;
    var index = options.index || 0;
    var speed = options.speed || 33;
    var pause = options.pause || 1000;
    var random = options.random || false;
    var list = options.list || [];
    var timer = null;
    var char_cursor = null;
    var mask_active = true;

    function init() {
        timer = setTimeout(next, pause);
    }

    function next() {
        if (mask_active) {
            char_cursor = element.textContent.length - 1;
            timer = setInterval(mask_text, speed);
            mask_active = false;
        } else {
            char_cursor = 0;
            timer = setInterval(reveal_text, speed);
            mask_active = true;
        }
    }

    function get_next_index() {
        return (index < list.length - 1) ? index + 1 : 0;
    }

    function reveal_text() {
        if (char_cursor < list[index].length) {
            var character = list[index].substr(char_cursor, 1);
            var rand_length = element.textContent.length - char_cursor - 1;
            var rand_text = gen_random_string(rand_length);
            element.textContent = element.textContent.substr(0, char_cursor) + character + rand_text;
            char_cursor++;
        } else if (char_cursor < element.textContent.length) {
            var rand_length = (element.textContent.length - list[index].length - 1);
            var rand_text = gen_random_string(rand_length);
            element.textContent = element.textContent.substr(0, list[index].length) + rand_text;
            if (element.textContent.length == list[index].length) {
                char_cursor++;
            }
        }
        if (char_cursor >= list[index].length && char_cursor >= element.textContent.length) {
            char_cursor = 0;
            index = get_next_index();
            clearInterval(timer);
            setTimeout(next, pause);
        }
    }

    function mask_text() {
        var rand_length = element.textContent.length - char_cursor;
        var rand_text = gen_random_string(rand_length);
        element.textContent = element.textContent.substr(0, char_cursor) + rand_text;
        char_cursor--;
        if (char_cursor == 0) {
            clearInterval(timer);
            next();
        }
    }

    function gen_random_string(length) {
        var string = '';
        for (var i = 0; i < length; i++) {
            string += String.fromCharCode(Math.floor(Math.random() * 26) + 65);
        }
        return string;
    }
    init();
}
if (window.jQuery) {
    (function() {
        $.fn.TickerScrambler = function(options) {
            return this.each(function() {
                $(this).data('TickerScrambler', new TickerScrambler($(this)[0], options))
            });
        }
    })(window.jQuery);
}
