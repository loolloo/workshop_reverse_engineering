//
// chall3
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

char *encoder(char *input)
{
    int key = 1;
    char *encodedPasswd = malloc(sizeof(char) * strlen(input) + 1);
    for (int i = 0; input[i] != '\0'; i++) {
        encodedPasswd[i] = input[i] - key;
        key++;
	key %= 0x20;
    }
    encodedPasswd[strlen(input)] = '\0';
    return (encodedPasswd);
}

void check(char *input, char *encodedPassword)
{
    char *encodedInput = encoder(input);

    int i = 0;
    for (i; encodedInput[i] == encodedPassword[i] && encodedInput[i]; i++);

    if (encodedInput[i]) {
        printf("Failed !\n");
    } else {
        printf("Success you can use this as the flag: %s\n", input);
    }
}

int main(int ac, char **av)
{
    char password[] = "o_por^tD\\jhSGdjO0M`TTP]GLTHSGKOg^reenYmad[r"; // passwd{Lets_Try_A_shift_encoding_this_time}
    if (ac != 2) {
        puts("Usage: ./passwd4 <password>");
        return 1;
    }
    check(av[1], password);
    return 0;
}
