#!/usr/bin/python3
"""This module defines a function that returns True or False"""


def canUnlockAll(boxes):
    """Takes in a list of boxes and returns True if all boxes can be unlocked,
    otherwise it returns False."""

    unlocked_indexes = [0]
    for i, box in enumerate(boxes):
        if i == 0:
            unlocked_indexes.extend(boxes[0])
            continue
        for key in box:
            if key not in unlocked_indexes and box != boxes[len(boxes) - 1]:
                unlocked_indexes.append(key)
    return (len(unlocked_indexes) == len(boxes))
