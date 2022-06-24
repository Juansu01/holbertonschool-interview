#!/usr/bin/python3
"""
This module defines a function that validates a data set
which represents a UTF-8 encoding.
"""


def validUTF8(data):
    """
    Returns True if data is a valid UTF-8 encoding,
    False otherwise.
    """
    if type(data) != list:
        return False
    counter = 0
    for el in data:
        if counter == 0:
            if (el >> 3) == 0b11110:
                counter = 3
            elif (el >> 4) == 0b1110:
                counter = 2
            elif (el >> 5) == 0b110:
                counter = 1
            elif (el >> 7):
                return False
        else:
            if (el >> 6) != 0b10:
                return False
            counter -= 1
    return counter == 0
