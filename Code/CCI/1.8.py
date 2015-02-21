# Assume we have a method called isSubstring which checks
# if one word is a substring of another word. Given two
# strings, s1 and s2, write code to check if s2 is a
# rotation of s1 by only calling isSubstring once.


def check_if_substring(s1, s2):
    # If s2 is a rotation, then it will be a substring of
    # s1 + s1.
    if len(s1) != len(s2):
        return False

    if s2 in s1 + s1:
        return True
    else:
        return False

tests = [
            ["rawr", "rraw"],
            ["asd", "sda"],
            ["waterbottle", "bottlewater"],
            ["Dog", "Elephant"]
        ]

for pair in tests:
    print pair
    print check_if_substring(pair[0], pair[1])
