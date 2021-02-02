#!/bin/bash

flag_file="$1"
[ -f "$flag_file" ] || (echo "Usage: ./verify_maker.sh flag_file" && exit 1)

# Print the part before the hashes
cat <<EOF
#!/bin/python3

from hashlib import md5
from sys import argv

flag_hashes = [
EOF

# Fill in the hashes
for flag in $(< $flag_file); do
    echo "    '$(echo -n $flag | md5sum | cut -d ' ' -f 1)',"
done

# Print the rest of the script
cat <<EOF
]

def usage():
    print("""Description:
    This program will verify if the flag you found is the correct one
    Don't forget the single quotes around the flag ( ' ) otherwise characters
    like ( ! ) or ( $ ) might change your argument in bash
Usage:
    ./verify 'flag{??????????????}'

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
EOF
