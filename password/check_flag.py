#!/bin/python3

from hashlib import md5
from sys import argv

flag_hashes = [
    'b8760c22ce2a8b4495f5d2986c111338',
    '361ac7ebda7f3a3782d8c3912ff6c336',
    'aee98ad72c21936c78c946b29c2989a1',
    '8044d5b0813469fce4ca7e88aaac2843',
    '1680ddb46f508d994c4a7d593e794bc8',
]

def usage():
    print("""Description:
    This program will verify if the flag you found is the correct one
    Don't forget the single quotes around the flag ( ' ) otherwise characters
    like ( ! ) or ( $ ) might change your argument in bash
Usage:
    ./verify 'passwd{??????????????}'

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
