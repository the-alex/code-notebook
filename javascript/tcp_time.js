var net = require('net');
// Get first command line argument => Port Number
var port_num = process.argv[2];
var date = new Date();

// Takes a component of the time. Month / Day / Hour / Minute -- anything that may need a '0' prepended to it.
// Expects metric === string
var format = function (metric) {
    if (metric.length < 2) {
        return '0' + metric;
    }
    else {
        return metric;
    }
};

var server = net.createServer(function (socket) {
    console.log('Client Connected ...');
    socket.on('end', function () {
        console.log('Client Disconnected');
    });

    // Date Format :: "YYYY-MM-DD hh:mm
    var date_year = date.getFullYear().toString();

    // Get the month, convert it to a string ...
    var date_month = format((date.getMonth() + 1).toString());
    // Do the same for each date component string ...
    var date_day = date.getDate();
    var date_hours = format(date.getHours().toString());
    var date_minutes = format(date.getMinutes().toString());

    // TODO :: Finish building string
    var date_string = date_year + '-' + date_month + '-' + date_day + ' ' + date_hours + ':' + date_minutes + '\n';


    socket.write(date_string);
    socket.end();
});
server.listen(port_num);

