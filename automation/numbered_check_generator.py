#!/bin/python3

from sys import argv
from random import shuffle

def usage():
    print("""USAGE
    ./numbered_check_generator.py string [-r]
DESCRIPTION
    string    the string you want the code to check for
    -r        enable random shuffling of the indexes
""")

def generate_check_functions(inp):
    for i, c in enumerate(inp):
        if c != "\n" and c != "'":
            print("int check_" + str(i) + "(char c) { if (c == '" + c + "') return 1; else return 0; } ")
        elif c == "\n":
            print("int check_" + str(i) + "(char c) { if (c == '\\n') return 1; else return 0; } ")
        else:
            print("int check_" + str(i) + "(char c) { if (c == '\\'') return 1; else return 0; } ")
 
def header(inp):
    print("""//
// auto3.c
//

#include <stdio.h>
""")
    generate_check_functions(inp)
    print("""
int check(char *input)
{
    puts("OK This is my last chance and I'm goint to give it my all!\\nLet's see you reversing this!");
""")

def tail():
    print("""    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        puts("Usage: ./auto3 <password>");
        return 1;
    }
    if (check(av[1]) == 0)
        puts("Success! dang, I guess you beat me on this one");
    else
        puts("Failed! Haha gotcha!");
    return 0;
}""")

def index_str(input_string, rand=False):
    s = list(enumerate(input_string))
    if rand:
        shuffle(s)
    for i, c in s:
        print(f"""    if (!check_{i}(input[{i}]))
        return 1;""")

if __name__ == "__main__":
    if len(argv) not in [2, 3]:
        usage()
        exit(1)

    header(argv[1])
    index_str(argv[1], "-r" in argv)
    tail()
