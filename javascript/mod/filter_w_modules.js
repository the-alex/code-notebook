// This program takes two arguments ...
// First :: Target Directory
var target_dir = process.argv[2]
// Second :: extension
var ext = process.argv[3]

// Import our function from the other file.
var filterFunc = require('./filter_mod')

filterFunc(target_dir, ext, function (err, data) {
    if (err) {
        console.log('Error in filterFunc :: callback', err)
    }

    data.forEach(function (datum) {
        console.log(datum)
    })
})
