import numpy as np

a = 4
# A = [[1, 1, 1], [2, 3, a], [1, 2, 3]]
# B = [[1, 1, 1], [3, a, 1], [2, 3, 1]]

# r1 = np.linalg.matrix_rank(A)
# r2 = np.linalg.matrix_rank(B)
# print(r1)
# print(r2)

C = [
    [0, 0, 1, 0],
    [0, 0, 0, 1],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
]

C2 = [
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1],
    [0, 0, 0, 0],
]

R = np.dot(C2, C2)
print(R)
