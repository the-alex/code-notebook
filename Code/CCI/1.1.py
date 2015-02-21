# Implement an algorithm to determine if a string has all
# unique characters in it. What if you cannot use additional
# data structures?

def all_chars_unique(string):
    charsSoFar = dict()
    for char in string:
        if char in charsSoFar:
            return False
        else:
            charsSoFar[char] = True
    return True

def no_extra_data_structures(string):
    # The complexity takes a hit, but I believe this is the
    # only way to do it.
    string_length = len(string)
    for i in range(string_length):
        for j in range(string_length):
            if i == j:
                continue
            elif string[i] == string[j]:
                return False
    return True


# Tests for all_chars_unique
unique = ["abc", "dfg", "asfuih"]
nonUnique = ["rawr", "asda", "aaa"]

# Expecting all True
for string in unique:
    result = all_chars_unique(string)
    if result != True:
        print "Failed on input", string
    else:
        print "Passed on input", string


# Expecting all False
for string in nonUnique:
    result = all_chars_unique(string)
    if result != False:
        print "Failed on input", string
    else:
        print "Passed on input", string



# Tests for no_extra_data_structures

# Expecting all True
for string in unique:
    result = no_extra_data_structures(string)
    if result != True:
        print "Failed on input", string
    else:
        print "Passed on input", string


# Expecting all False
for string in nonUnique:
    result = no_extra_data_structures(string)
    if result != False:
        print "Failed on input", string
    else:
        print "Passed on input", string

