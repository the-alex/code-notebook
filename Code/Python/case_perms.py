def print_rows(matrix):
    for row in matrix:
        print(row)

# Write code to generate all possible case combinations of a
# given lower-cased string.
# (e.g. "0ab" -> ["0ab", "0aB", "0Ab", "0AB"])

#   a b
#   a B
#   A b
#   A B
#
# Notice how it's similar to the strategy of generating
# possible binary inputs.
#
#   0 0 0
#   0 0 1
#   0 1 0
#   0 1 1
#   1 0 0
#   1 0 1
#   1 1 0
#   1 1 1
#
# The characters don't matter because their positioning
# is determined for you. What matters is if they are
# capitalized or not. Which makes this problem very
# similar to the binary one above. The position of the
# bits are set. It's a matter of whether they're a one
# or a zero.
#
# Lets try writing a general function using bits, and then
# map the ideas of that function to case_perms.
#
# It's like the opposite of mapping reducibility!

def case_perms(string):
    # In the other function, we knew the bit length. Here,
    # we'll have to find it by looping through the string to
    # see how many alphabetical characters there are.

    # Get the indicies of the non-alpha characters in the
    # string. We're gonna gen the strings and then just
    # add the non-alpha characters after we have the perms.


    char_length = max([i for i in range(len(string)) if string[i].isalpha()])

    # char_length determines the number of "rows" but
    # len(string) determines the cols.

    num_strings = 1 << char_length
    case_strings = []

    for index in range(num_strings):
        case_strings.append([])




    return case_strings



def bit_perms(bit_length):
    # If we look at the first column of bits, we see that
    # the number of 0's and 1's respectively is
    # bit_length / 2 ... Each subsequent column experiences
    # repetitions of a similar form. Column size is
    # "1 << bit_length"
    # col:
    #   1 => 8 / 2 (or 1 << 1)
    #   2 => 8 / 4 (or 1 << 2)
    #   3 => 8 / 8 (or 1 << 3)

    num_strings = 1 << bit_length
    bit_strings = []

    for index in range(num_strings):
        bit_strings.append([])

    # I'm keeping track of what to print at each iteration
    # by using modulo to sense when the col should be print-
    # ing zeros. This seems super hacky and took way too
    # long to figure out. Part of the problem was the way in
    # which python treats data structures initialized like
    # this ... "bit_strings = [] * 10" ... This one empty
    # list referenced ten times. So any changes to one cell
    # will be reflected in every cell. Very annoying.
    printZero = False

    # Iterates three times, where reps is
    # [4, 2, 1] sequentially.

    for reps in [(num_strings >> i + 1) for i in range(bit_length)]:
        for row in range(num_strings):
            if (row % reps) == 0:
                printZero = not printZero
            if printZero:
                bit_strings[row].append('0')
            else:
                bit_strings[row].append('1')

    return bit_strings

print_rows(case_perms("0ab"))
