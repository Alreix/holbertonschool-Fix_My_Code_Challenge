#!/usr/bin/node
/*
    Print a square with the character #

    The size of the square must be the first argument
    of the program.
*/

if (process.argv.length <= 2) {
    process.stderr.write("Missing argument\n");
    process.stderr.write("Usage: ./1-print_square.js <size>\n");
    process.stderr.write("Example: ./1-print_square.js 8\n");
    process.exit(1);
}

// The second argument of parseInt is the numeric base.
// The size must be read as a normal decimal number, so we use base 10.
// With base 16, "10" is interpreted as hexadecimal and becomes 16.
let size = parseInt(process.argv[2], 10);

for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
        process.stdout.write("#");
    }
    process.stdout.write("\n");
}
