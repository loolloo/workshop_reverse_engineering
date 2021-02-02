#!/bin/python3

from sys import argv
from random import shuffle

def usage():
    print("""USAGE
    ./index_check_generator.py string [-r]
DESCRIPTION
    string    the string you want the code to check for
    -r        enable random shuffling of the indexes
""")

def header():
    print("""//
// auto1.c
//

#include <stdio.h>

int check(char *input)
{
    puts("If you're going to see this anyways,\\nwhy not go all the way and make this as annoying as possible ;)");
""")

def tail():
    print("""    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        puts("Usage: ./auto1 <password>");
        return 1;
    }
    if (check(av[1]) == 0)
        puts("Success! You are the index champion");
    else
        puts("Failed! Index your stuff a better way next time");
    return 0;
}""")

def index_str(input_string, rand=False):
    s = list(enumerate(input_string))
    if rand:
        shuffle(s)
    for i, c in s:
        print(f"""    if (input[{i}] != {hex(ord(c))})
        return 1;""")

if __name__ == "__main__":
    if len(argv) not in [2, 3]:
        usage()
        exit(1)

    header()
    index_str(argv[1], "-r" in argv)
    tail()

