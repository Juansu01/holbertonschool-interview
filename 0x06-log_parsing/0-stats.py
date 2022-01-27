#!/usr/bin/python3
"""Reads from sdtin and outputs stats."""

from sys import stdin
from collections import OrderedDict


def printit(size, _dict):
    print("File size: {}".format(size))
    for key, val in _dict.items():
        if val != 0:
            print("{} :{}".format(key, val))


if __name__ == '__main__':
    counter = 0
    file_size = 0
    status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    ordered_codes = OrderedDict()
    for code in status_codes:
        ordered_codes[code] = 0
    try:
        for line in stdin:
            counter += 1
            try:
                args = line.split()
                file_size += int(args[-1])
                if args[-2] in status_codes:
                    ordered_codes[args[-2]] += 1
            except Exception:
                pass
            if counter % 10 == 0:
                printit(file_size, ordered_codes)
    except KeyboardInterrupt:
        printit(file_size, ordered_codes)
        raise
    printit(file_size, ordered_codes)
