var fs = require('fs');
// Print the contents of a given directory.

// First argument => path to dir
var path_to_dir = process.argv[2];

// Second argument => extension
var ext  = '.' + process.argv[3];

fs.readdir(path_to_dir, function (err, list) {
    if (err) { console.log(err); }
    // For each item in the list of files ...
    for (var i = 0; i < list.length; ++i) {
        // check the file extension matches the target extension
        var this_file = list[i];
        // Split the file name up to look at the fileName.length - ext.length to fileName.length
        if ( ext == this_file.slice(this_file.length - ext.length, this_file.length)  ) {
            console.log(this_file);
        }
    }
});

// Official Solution
//  ar fs = require('fs');
//  ar path = require ('path');
//
//  s.readdir(process.argv[2], function (err, list) {
//     list.forEach(function (file) {
//         if (path.extname(file) === '.' + process.argv[3]) {
//             console.log();
//         }
//     })
//  )
