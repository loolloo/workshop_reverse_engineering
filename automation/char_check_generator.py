#!/bin/python3

from sys import argv
from random import shuffle

def usage():
    print("""USAGE
    ./char_check_generator.py string [-r]
DESCRIPTION
    string    the string you want the code to check for
    -r        enable random shuffling of the indexes
""")

charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.?!'\" ()\n"
special_repr = {
    ",": "coma",
    ".": "dot",
    "?": "question_mark",
    "!": "exclamation_mark",
    " ": "space",
    "'": "quote",
    '"': "double_quote",
    " ": "space",
    "(": "left_parenthesis",
    ")": "right_parenthesis",
    "\n": "newline"
}

def get_char_functions():
    functions = []
    for c in charset:
        if not c in special_repr.keys():
            name = c
        else:
            name = special_repr[c]

        if c == "\n":
            functions += ["int check_char_" + name + "(char c) { return c == '\\n'; }"]
        elif c == "'":
            functions += ["int check_char_" + name + "(char c) { return c == '\\''; }"]
        else:
            functions += ["int check_char_" + name + ("(char c) { return c == '%s'; }" % c)]

    return "\n".join(functions)

def header():
    print("""//
// auto2.c
//

#include <stdio.h>
""")
    print(get_char_functions())
    print("""
int check(char *input)
{
    puts("Last time our review team decided that it was too annoying for us,\\nTo solve this, we put every check in it's own function");
""")

def tail():
    print("""    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        puts("Usage: ./auto2 <password>");
        return 1;
    }
    if (check(av[1]) == 0)
        puts("Success! You're the check funcion master I guess?");
    else
        puts("Failed! I guess this is too hard to read for you");
    return 0;
}""")

def index_str(input_string, rand=False):
    s = list(enumerate(input_string))
    if rand:
        shuffle(s)
    for i, c in s:
        if not c in special_repr.keys():
            name = c
        else:
            name = special_repr[c]

        print(f"""    if (!check_char_{name}(input[{i}]))
        return 1;""")

if __name__ == "__main__":
    if len(argv) not in [2, 3]:
        usage()
        exit(1)

    header()
    index_str(argv[1], "-r" in argv)
    tail()
