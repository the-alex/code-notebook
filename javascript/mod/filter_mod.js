// We use this library to access the file system.
//  fs => readdir(dir, <callback>)
var fs = require('fs')

// We use the path library for it's string manipulations
//  path => extname(<fileName>) :: returns the extension on the file.
var path = require('path')

// This export allows other files to access this function.
//  Note :: because this function is asynchronous, we include a callback function parameter.
module.exports = function (dir, extString, callback) {
    // First, we make an asynchronous call to get the files in the dir ...
    fs.readdir(dir, function (err, data) {
        // If there is an error, terminate early ...
        if (err) {
            // ... specifically, with the 'err' parameter on the callback that was passed in.
            //      We're passing it "up" the callback chain.
            return callback(err)
        }

        // Look at each element in the list of file names in the specified directory ...
        //  SideNote :: We know we succeeded by this point because if there was an error, we would have
        //  terminated early.
        data = data.filter(function (file) {
            // ... and filter the list base on this function we pass in.
            // Membership in 'data' is now determined by this filter function returning an element.
            return path.extname(file) === '.' + extString
        })

        // By this point, we can now return the data into the callback we passed into this function.
        //  SideNote :: Notice the idiomatic parameters. We're setting err == null and the data section
        //  to the motified data value we created in this function.
        callback(null, data)
    })
}

