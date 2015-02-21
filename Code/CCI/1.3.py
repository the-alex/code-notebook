# Given two strings, define a function that determines if
# one is a permutation of the other.

# Questions:
#   Must a permutation of the string and the string itself
#   have the same length?

def are_permutations(string_A, string_B):
    letters_of_A = dict()
    letters_of_B = dict()

    for char in string_A:
        if char in letters_of_A:
            letters_of_A[char] += 1
        else:
            letters_of_A[char] = 1

    for char in string_B:
        if char in letters_of_B:
            letters_of_B[char] += 1
        else:
            letters_of_B[char] = 1

    for letter in letters_of_A:
        if letter not in letters_of_B:
            return False
        if letters_of_A[letter] != letters_of_B[letter]:
            return False

    return True


# Tests
#                          Any Gun's n' Roses fans?
tests = [("rawr", "rwar"), ("axl_rose", "oral_sex"), ("cat", "dog")]

for pair in tests:
    print pair
    print are_permutations(pair[0], pair[1])
