//
// chall2
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

int second_check(char *input)
{
    if (input[0] != 'u')
	return 0;
    if (input[1] != '_')
	return 0;
    if (input[2] != 'p')
	return 0;
    if (input[3] != 'a')
	return 0;
    if (input[4] != 's')
	return 0;
    if (input[5] != 's')
	return 0;
    return 1;
}

int check(char *input)
{
    if (input[0] != 'R')
	return 0;
    if (input[1] != 'O')
	return 0;
    if (input[2] != 'F')
	return 0;
    if (input[4] != '_')
	return 0;
    if (input[3] != 'L')
	return 0;
    return second_check(&input[5]);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        puts("Usage: ./passwd3 <password>");
        return 1;
    }

    if (check(av[1])) {
	printf("Success! your flag is passwd{%s}\n", av[1]);
    } else {
	puts("Failed! You can try again ;)");
    }
    return 0;
}
