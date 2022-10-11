#!/usr/bin/python3
""" Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Rotates matrix in place.
    Doesn't return anything
    """

    for i in range(len(matrix[0])-1, -1, -1):
        for j in range(len(matrix)):
            matrix[j].append(matrix[i].pop(0))
