#!/usr/bin/python3
"""
Interview pratice.
"""


def makeChange(coins, total):
    """
    Returns the minimum amount of coins required to reach
    total, -1 if the minimum amount was not found.
    """

    if total <= 0:
        return 0

    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if amount - coin >= 0:
                dp[amount] = min(dp[amount], 1 + dp[amount - coin])
    return dp[total] if dp[total] != total + 1 else -1
