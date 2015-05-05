var fs = require('fs');
// Read target file path
var path_to_file = process.argv[2]
fs.readFile(path_to_file, function (err, data) {
    if (err) { console.log(err) }
    console.log(data.toString().split('\n').length - 1);
});

