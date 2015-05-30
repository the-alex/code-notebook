var http = require('http');
var fs = require('fs');

// Get the path to the payload.
var port = process.argv[2];

// path to text file we want to serve.
var fpath = process.argv[3];

var server = http.createServer(function (req, res) {
    fs.readFile(fpath, function (err, data) {
        if (err) { console.log(err); }

        res.writeHead(200, {'Content-Type': 'text/plain'});
        fs.createReadStream(fpath).pipe(res);
    });
});

server.listen(port, 'localhost');

