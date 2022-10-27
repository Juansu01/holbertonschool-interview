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
        return -1

    nums = [float('inf') for x in range(total + 1)]
    nums[0] = 0

    for coin in coins:
        for amount in range(len(nums)):
            if coin <= amount:
                nums[amount] = min(nums[amount], 1 + nums[amount - coin])

    if nums[total] != float('inf'):
        return nums[total]

    return -1
