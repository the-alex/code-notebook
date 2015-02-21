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


print "Tests for all_chars_unique"
unique = ["abc", "dfg", "asfuih"]
nonUnique = ["rawr", "asda", "aaa"]

print "Expecting all True"
for string in unique:
    if all_chars_unique(string):
        print "True on input", string
    else:
        print "False on input", string

print

print "Expecting all False"
for string in nonUnique:
    if all_chars_unique(string):
        print "True on input", string
    else:
        print "False on input", string

print

print "Tests for no_extra_data_structures"
print "Expecting all True"
for string in unique:
    if no_extra_data_structures(string):
        print "True on input", string
    else:
        print "False on input", string

print

print "Expecting all False"
for string in nonUnique:
    if no_extra_data_structures(string):
        print "True on input", string
    else:
        print "False on input", string
