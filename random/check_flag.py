#!/bin/python3

from hashlib import md5
from sys import argv

flag_hashes = [
    'e3412bc4bc410dabce22e5f7a215e884',
    '6847740225e7deb658efc9a627600954',
    'afc1a08001318dc6e980796b228cfc9b',
]

def usage():
    print("""Description:
    This program will verify if the flag you found is the correct one
    Don't forget the single quotes around the flag ( ' ) otherwise characters
    like ( ! ) or ( $ ) might change your argument in bash
Usage:
    ./verify 'random{??????????????}'

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
