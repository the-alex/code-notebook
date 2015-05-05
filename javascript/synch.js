// Alright, the gaol of this one is to count the number of new lines in a file.
// Load the FS module
var fs = require('fs');

// Get the target file from command line args
var path_to_file = process.argv[2];

// Open the target file. fs.readFileSync returns a buffer object.
var target = fs.readFileSync(path_to_file);

// Load target file into a string. buf.toString() will do what I want.
var contents = target.toString();

// Save a split version of the file into an array.
var split_contents = contents.split('\n');

// Output the length of that array as the number of newlines in the file.
// The reason this has a - 1 is because if you split by '\n', then you end up with a ''
// as the last element in the split_contents array.
var num_newlines =  split_contents.length - 1;
console.log(num_newlines);

