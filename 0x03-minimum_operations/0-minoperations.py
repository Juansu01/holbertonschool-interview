#!/usr/bin/python3
"""
This module defines the minimum operations
function.
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to
    result in exactly n H characters in the file
    """

    if type(n) is not int:
        return 0

    iterator = 2
    operations = 0

    while iterator <= n:
        if not (n % iterator):
            n = int(n / iterator)
            operations += iterator
            iterator = 1
        iterator += 1

    return operations
