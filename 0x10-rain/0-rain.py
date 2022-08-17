#!/usr/bin/python3
"""
Rain interview practice.
"""


def rain(walls):
    """
    Calculates how many square units of
    water will be retained after it rains.
    """

    if not walls or type(walls) != list:
        return 0

    for num in walls:
        if num < 0:
            return 0

    water = 0

    for i, height in enumerate(walls):
        max_r = max(walls[i:])
        max_l = max(walls[:i + 1])

        short_wall = min(max_l, max_r)
        water += max(short_wall - height, 0)
    return water
#%%