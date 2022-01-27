#!/usr/bin/python3
"""Reads from sdtin and outputs stats."""

from sys import stdin
from collections import OrderedDict

if __name__ == "__main__":
    counter = 0
    file_size = 0
    status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    ordered_codes = OrderedDict()
    for code in status_codes:
        ordered_codes[code] = 0
    try:
        for line in stdin:
            try:
                args = line.split()
                file_size += int(args[-1])
                if args[-2] in status_codes:
                    ordered_codes[args[-2]] += 1
            except Exception:
                pass
            counter += 1
            if counter % 10 == 0:
                print("File size: {}".format(file_size))
                for key, val in ordered_codes.items():
                    if val != 0:
                        print("{} :{}".format(key, val))
    except KeyboardInterrupt:
        print("File size: {}".format(file_size))
        for key, val in ordered_codes.items():
            if val != 0:
                print("{} :{}".format(key, val))
        raise
    print("File size: {}".format(file_size))
    for key, val in ordered_codes.items():
        if val != 0:
            print("{} :{}".format(key, val))
