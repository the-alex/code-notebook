# Given an NxN matrix of pixels in an image where each pixel
# 4 bytes, write a method to rotate the image 90 degrees.
# Can you do this in place?
#
# Yes, you can do it in place.
#  However, I did not.

from copy import deepcopy


def print_rows(matrix):
    for row in matrix:
        print row


def rotate(matrix):
    length = len(matrix[0])

    new_matrix = deepcopy(matrix)

    for i in range(length):
        for j in range(length):
            new_matrix[i][j] = 'x'

    # construct a new matrix of blank values. Calculate as
    # follows ...
    #   p(i, j) => p_(x, y) where x = j and i = N - 1 - i

    for i in range(length):
        for j in range(length):
            new_matrix[j][length - 1 - i] = matrix[i][j]

    return new_matrix


tests = [
    [['*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
     ['*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
     ['*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
     ['*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' '],
     ['*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' '],
     ['*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' '],
     ['*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' '],
     ['*', '*', '*', '*', '*', '*', '*', '*', ' ', ' '],
     ['*', '*', '*', '*', '*', '*', '*', '*', '*', ' '],
     ['*', '*', '*', '*', '*', '*', '*', '*', '*', '*']],
    [['a', 'b', 'c'],
     ['d', 'e', 'f'],
     ['g', 'h', 'i']]
]

for image in tests:
    print_rows(image)
    print
    print_rows(rotate(image))
    print
