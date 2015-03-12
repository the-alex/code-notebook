# Given an array holding integers from 0 to N - 1, with one
# element replaced with another already in the array. Find
# the duplicate item in O(n) time.
from random import randint

def find_duplicate(array):
    N = len(array)
    supposed_sum = N * (N - 1) / 2
    supposed_squares_sum = N * (N - 1) * (2 * N - 1) / 6

    this_sum = sum(array)
    this_squares_sum = sum([i ** 2 for i in array])

    A = supposed_sum - this_sum
    B = (supposed_squares_sum - this_squares_sum) / A



    duplicate = (B + A) / 2
    number_it_replaced = (B - A) / 2

    return (duplicate, number_it_replaced)

if __name__ == '__main__':

    for i in range(100):
        size = randint(2, 100)
        victim = randint(0, size - 1)
        duplicate = randint(0, size - 1)

        if victim == duplicate:
            continue

        array = range(size)
        array[victim] = duplicate

        found_victim, found_duplicate = find_duplicate(array)

        assert((victim == found_victim) and (duplicate == found_duplicate))

        print
        print "Test", i
        print "Size:", size
        print "Victim:", victim
        print "Duplicate:", duplicate
        print
        print "Victim Calculated:", found_victim
        print "Duplicated Calculated:", found_duplicate
        print

