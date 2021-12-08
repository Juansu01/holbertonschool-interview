#!/usr/bin/python3
"""This module defines a function that returns True or False"""


def canUnlockAll(boxes):
    """Takes in a list of boxes and returns True if all boxes can be unlocked,
    otherwise it returns False."""

    unlocked_indexes = []
    for i, box in enumerate(boxes):
        if i == 0:
            unlocked_indexes.extend(boxes[0])
            continue
        if i != 0 and i in unlocked_indexes:
            unlocked_indexes.extend(box)
    mylist = list(dict.fromkeys(unlocked_indexes))
    mylist = sorted(mylist)
    if 0 not in unlocked_indexes:
        mylist.insert(0, 0)
    for i in mylist:
        for j in boxes[i]:
            if j not in mylist:
                mylist.append(j)
    mylist = sorted(mylist)
    if len(mylist) != len(boxes):
        return False
    return True
