#!/usr/bin/python3
"""
Given a pile of coins of different values.
"""


def makeChange(coins, total):
    """Given a pile of coins of different values."""

    number_coins = 0
    cents = 0
    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while cents + coin <= total:
            cents += coin
            number_coins += 1
        if cents == total:
            return number_coins
    return -1
