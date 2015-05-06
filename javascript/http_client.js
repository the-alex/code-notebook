// Takes a URL as an argument and prints the data in the HTTP response object.
var datURL = process.argv[2];
// require the 'http' library
var http = require('http');

http.get(datURL, function (response) {
    response.setEncoding('utf8');
    // When the data becomes available on the response object, do this ...
    response.on('data', function (data) {
        console.log(data);
    });
    response.on('error', console.error);
});

