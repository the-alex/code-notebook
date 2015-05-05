// Create the running sum.
var sum = 0;
for (var i = 2; i < process.argv.length; ++i) {
    // For each item in the array, add the numeric argument to the running sum.
    sum += Number(process.argv[i]);
}
// Print the sum to the console.
console.log(sum);
