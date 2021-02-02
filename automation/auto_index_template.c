//
// auto1.c
//

#include <stdio.h>

int check(char *input)
{
    puts("If you're going to see this anyways,\nwhy not go all the way and make this as annoying as possible ;)");
    if (input[?] != '?')
	return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) {
	puts("Usage: ./auto1 <password>")
    }
    if (check(av[1]) == 0)
	puts("Success! You are the index champion!");
    else
	puts("Failed! Index your stuff a better way next time")
    return 0;
}
