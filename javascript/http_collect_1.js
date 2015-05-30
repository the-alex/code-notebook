// Include http library.
var http = require('http');
// Get the url from the command line. (first arguemnt, index = 2)
var target_URL = process.argv[2];

var running_data = "";

// Make "get" request.
http.get(target_URL, function (response) {
    response.setEncoding('utf8');
    // When a "data" response comes in ...
    response.on('data', function (data) {
        running_data += data.toString();
    });
    // When we're done receiving data ...
    response.on('end', function (data) {
        console.log(running_data.length);
        console.log(running_data);
    });
    // When an 'error' response comes in ...
    response.on('error', function (err) {
        console.log(err);
    });
});

