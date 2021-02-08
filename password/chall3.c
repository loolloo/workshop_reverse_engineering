//
// chall3
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

char *encodePassword(char *input)
{
    int key = 1;
    char *encodedPasswd = malloc(sizeof(char) * strlen(input) + 1);
    for (int i = 0; input[i] != '\0'; i++) {
        encodedPasswd[i] = input[i] + key;
        key++;
    }
    encodedPasswd[strlen(input)] = '\0';
    return (encodedPasswd);
}

void cmp_wide_str(char *input, char *encodedPassword)
{
    char *decodedPassword = encodePassword(encodedPassword);
    for (int i = 0; decodedPassword[i]; i++) {
        if (input[i] != decodedPassword[i]) {
            printf("Perdu !\n");
            return;
        }
    }
    printf("You found it:%s\n", input);
    return;
}

int main(int ac, char **av)
{
    char password[] = "o_por^tJ*lZffWn"; //passwd{R3verse} clef hexa : 0x12
    if (ac != 2) {
        puts("Usage: ./chall3 password");
        return 1;
    }
    cmp_wide_str(av[1], password);
    return 0;
}
