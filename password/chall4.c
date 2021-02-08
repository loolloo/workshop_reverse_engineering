//
// chall4
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


char *decodePassword(char *encodedPassword, char key)
{
    char *decodedPassword = malloc(sizeof(char) * strlen(encodedPassword) + 1);

    for (int i = 0; encodedPassword[i] != '\0'; i++)
        decodedPassword[i] = encodedPassword[i] ^ key;
    decodedPassword[strlen(encodedPassword)] = '\0';
    return (decodedPassword);
}

void cmp_wide_str(char *input, char *encodedPassword)
{
    char *decodedPassword = malloc(sizeof(char) * (strlen(encodedPassword)));
    int lenEncodedPassword = strlen(encodedPassword) - 1;
    
    for (int i = 0; i < strlen(encodedPassword) ; i++) {
        decodedPassword[i] = encodedPassword[lenEncodedPassword];
        lenEncodedPassword--;
    }
    decodedPassword = decodePassword(decodedPassword, 0x13);
    for (int index = 0; decodedPassword[index]; index++) {
        if (input[index] != decodedPassword[index]) {
            printf("you lost\n");
            return;
        }
    }
    printf("good you found the flag\n");
    return;
}

void show_password()
{
    char *passwd = "passwd{too easy no ?}";
    printf(passwd);
}

int main(int ac, char **av)
{
    char *password = "nwar{L`rdLv}|L`z{Ghwd``rc";
    if (ac != 2) {
        puts("Usage: ./chall4 password");
        return 1;
    }
    cmp_wide_str(av[1], password);
    return 0;
}
