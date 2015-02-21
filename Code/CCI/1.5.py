# Perform a basic string compression using the counts of
# repeated characters. For instance aabbbccccc would become
# a2b3c5. If the compressed string would not become smaller
# than the original, return the original string. The strings will
# only contain lowercase alphabetic characters.



def neive_compression(string):
    # [letter[count]]
    letter_count_pairs = list()

    # Trivially compressed if len(string) == 1
    if len(string) == 1:
        return string

    # Initialize the list to avoid an "if" in the for loop.
    letter_count_pairs.append([string[0], 0])

    for index, letter in enumerate(string):
        # If this letter and the last are the same, iterate.
        if letter == letter_count_pairs[-1][0]:
            letter_count_pairs[-1][1] += 1
        # otherwise, append a new tuple.
        else:
            letter_count_pairs.append([letter, 1])

    new_string = ""
    for pair in letter_count_pairs:
        new_string += pair[0] + str(pair[1])

    if len(new_string) >= len(string):
        return string

    return new_string


# Better for long strings consisting of words, or equivalent
# strings of low single character repetition.
def better_compression(string):
    # Loop through the string taking words (substrings
    # separated by spaces) and recording the index
    # they are at in a dictionary.
    #
    # For each word, there should be a pairing to a list of
    # indicies.
    #
    # The output should be every unique word followed by a
    # list of indecies relating to the positions of that
    # word in the string.
    #
    # Optimizations: You could encode the positions in a
    # different base to better save space. Ex. Hexadecimal
    # or base 36 (0..9a...z)
    pass



tests = ["aaabbcddd", "rawrasd", "a", "aabbcc"]

for string in tests:
    print "Testing string", string
    print neive_compression(string)
