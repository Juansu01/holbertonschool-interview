#!/usr/bin/python3
"""This module defines a function that returns True or False"""


def canUnlockAll(boxes):
    """Takes in a list of boxes and returns True if all boxes can be unlocked,
    otherwise it returns False."""

    unlocked_indexes = [0]
    for index in unlocked_indexes:
        for key in boxes[index]:
            if key not in unlocked_indexes:
                unlocked_indexes.append(key)
    return (len(boxes) == len(unlocked_indexes))
