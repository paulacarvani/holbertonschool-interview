#!/usr/bin/python3
"""
Given a pile of coins of different values.
"""


def makeChange(coins, total):
    """Given a pile of coins of different values."""
    if total == 0:
        return 0

    value = len(coins) - 1
    num_coins = 0
    coins.sort()

    while total > 0:
        while coins[value] > total and value >= 0:
            value -= 1
        total -= coins[value]
        num_coins += 1

    if all(total % coin != 0 for coin in coins):
        return -1

    return num_coins
