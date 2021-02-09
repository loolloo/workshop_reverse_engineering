#!/bin/python3

from hashlib import md5
from sys import argv

flag_hashes = [
    '73d8cc74f99365c0fda0da44dab8177b',
    'cce6437142fe4e1d22c0587fcf619f1b',
    'b8ff758f5def797c392bd03269c0e99b',
]

def usage():
    print("""Description:
    This program will verify if the flag you found is the correct one
    Don't forget the single quotes around the flag ( ' ) otherwise characters
    like ( ! ) or ( $ ) might change your argument in bash
Usage:
    ./verify 'auto{??????????????}'

if you want tips, try running the program with -tip
""")

def tip():
    print("get good lol")

if len(argv) != 2 or "-h" in argv:
    usage()
    exit(0)

if "-tip" in argv:
    tip()
    exit(0)

h = md5(argv[1].encode('utf-8')).hexdigest()

if h in flag_hashes:
    print("Success! You validated flag nb %d" % (flag_hashes.index(h) + 1))
else:
    print("Failed! try again")
