#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    """pascal_triangle"""
    pascal = []

    for i in range(0, n):
        pascal.append([])
        for j in range(0, i + 1):
            if j == 0 or j == i:
                pascal[i].append(1)
            else:
                pascal[i].append(pascal[i - 1][j] + pascal[i - 1][j - 1])
    return pascal
