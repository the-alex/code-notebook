#!/usr/local/bin/node
// Check if arguments were passed ...
if (process.argv.length !== 4) {
  process.stderr.write('Must supply path/to/file.md and path/to/file.pdf\n');
  process.exit(9);
}

var mpdf = require('markdown-pdf');
var fs = require('fs');
fs.createReadStream(process.argv[2])
  .pipe(mpdf())
  .pipe(fs.createWriteStream(process.argv[3]));
