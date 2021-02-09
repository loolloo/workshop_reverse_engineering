//
// chall2
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

char *encoder(char *input)
{
    char *out = malloc(sizeof(char) * strlen(input) + 1);

    for (int i = 0; input[i] != 0; i++) {
        out[i] = input[i] ^ 0x12;
    }

    out[strlen(input)] = 0;
    return out;
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
    char password[] = "bsaaeviJ}`Mw|q`kbf{}|M{aMfzwMpwaf<<<@{uzf-o"; // passwd{Xor_encryption_is_the_best...Right?}
    if (ac != 2) {
        puts("Usage: ./passwd2 <password>");
        return 1;
    }
    check(av[1], password);
    return 0;
}
