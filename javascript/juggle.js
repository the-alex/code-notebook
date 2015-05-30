var http = require('http');
var bl = require('bl');
var results = [];
// Use this var to keep track of how many responses have been seen so far.
var count = 0;

function printResults() {
    for (var i = 0; i < results.length; i++) {
        console.log(results[i]);
    }
}

function get_http(index) {
    // GET request the target URL, specificed by the index.
    http.get(process.argv[index + 2], function (response) {
        response.pipe(bl(function (err, data) {
            if (err) { return console.error(err); }
            data = data.toString();
            results[index] = data;
            count++;
            if (count === 3) {
                printResults();
            }
        }));
    });
}

for (var i = 0; i < 3; i++) {
    get_http(i);
}
