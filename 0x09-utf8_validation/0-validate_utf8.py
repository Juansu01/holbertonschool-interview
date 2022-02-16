#!/usr/bin/python3
"""
This module degfines a function that validates a data set
which represents a UTF-8 encoding.
"""


def validUTF8(data):
    """
    Returns True if data is a valid UTF-8 enconding,
    False otherwise.
    """
    if type(data) != list:
        return False
    counter = 0
    for el in data:
        if counter == 0:
            if (el >> 5) == 0b110:
                count = 1
            elif (el >> 4) == 0b1110:
                count = 2
            elif (el >> 3) == 0b11110:
                count = 3
            elif (el >> 7):
                return False
        else:
            if (el >> 6) != 0b10:
                return False
            counter -= 1
    return (counter == 0)
