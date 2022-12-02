#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1.
"""


def rain(walls):
    """Given a list of non-negative integers representing walls of width 1."""
    if (len(walls) <= 2):
        return (0)

    water = 0

    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for k in range(i + 1, len(walls)):
            right = max(right, walls[k])

        water += min(left, right) - walls[i]

    return water
