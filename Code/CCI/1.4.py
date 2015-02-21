# You are given a string and it's "true" length (number of
# characters plus the spaces in between alphanumeric
# characters). Replace all spaces with %20. Exclude trailing
# spaces.

# Questions:
#   Are the strings all alphanumeric or just alphabetical?
#       I'll assume they're alphanumeric. Pretty sure it
#       doesn't affect anything anyways.
#   Will there be leading spaces, or just trailing spaces?
#       Assuming there will be


import re

def make_string_url_safe(string, true_length):
    # First, remove any leading spaces.
    #
    # Then, replace all substrings consisting of only spaces with
    # length greater than one.
    #   This leaves only one space where there may have been
    #   many before.
    #
    # Locate the last character and check if it's a space.
    #   If it is, remove it.
    #
    # Check that len(string) == true_length
    #   if not, error
    #
    # replace all spaces with "%20"

    # Remove leading spaces
    while string[0] == ' ':
        string = string[1:]


    pattern = re.compile(ur'  ')
    while '  ' in string:
        string = re.sub(pattern, ' ', string)

    # Sanity check combined with a check for one last
    # trailing space (because the regex could only leave
    # a maximum of one space left).
    if len(string) != true_length:
        if string[-1] == ' ':
            string = string[:-1]

    pattern = re.compile(ur' ')
    # use regex to replace all spaces with "%20"
    string = re.sub(pattern, '%20', string)

    return string


tests = ["This is an input",
        "This is an     input",
        "      This input an input       "]

for string in tests:
    print "Testing", string
    print make_string_url_safe(string, 16)
