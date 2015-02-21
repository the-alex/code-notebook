# Write an algorithm such that if an element in an MxM
# matrix is 0, the entire row and column will be set to 0's

# Questions: Can there be more than 1 zero?
#   Assuming no, because this could cause many generated
#   zeros to trigger the algorithm.


def print_rows(matrix):
    for row in matrix:
        print row


def target_zeros(matrix):
    # Coordinates are given by x and y
    x = 0
    y = 0
    for i in range(len(matrix[0])):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
                x = i
                y = j
                break

    for i in range(len(matrix[0])):
        for j in range(len(matrix[0])):
            if i == x:
                matrix[i][j] = 0
            if j == y:
                matrix[i][j] = 0


tests = [
    [[1, 1, 1, 1],
     [1, 1, 1, 1],
     [1, 1, 1, 1],
     [1, 0, 1, 1]],

    [[1, 1, 1, 1],
     [1, 1, 0, 1],
     [1, 1, 1, 1],
     [1, 1, 1, 1]]
]

for matrix in tests:
    print_rows(matrix)
    print
    target_zeros(matrix)
    print_rows(matrix)
    print
