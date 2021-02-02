//
// chall2
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

char *encodePassword(char *input)
{
    char *encodedPasswd = malloc(sizeof(char) * strlen(input) + 1);
    for (int i = 0; input[i] != '\0'; i++) {
        encodedPasswd[i] = input[i] ^ 0x12;
    }
    encodedPasswd[strlen(input)] = '\0';
    return (encodedPasswd);
}

void cmp_wide_str(char *input, char *encodedPassword)
{
    char *decodedPassword = encodePassword(encodedPassword);
    for (int i = 0; decodedPassword[i]; i++) {
        if (input[i] != decodedPassword[i]) {
            printf("bark bark bark!\n");
            return;
        }
    }
    printf("You found it:%s\n", input);
    return;
}

int main(int ac, char **av)
{
    char password[] = "bsaaevi_!``kQz`#af&ao"; //passwd{M3rryChr1st4s} clef hexa : 0x12
    if (ac != 2) {
        puts("Usage: ./chall1 <password>");
        return 1;
    }
    cmp_wide_str(av[1], password);
    return 0;
}
