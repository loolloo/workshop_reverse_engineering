//
// rand2.c
//

#include <stdio.h>
#include <stdlib.h>

void show_flag(int n1, int n2)
{
    unsigned char password[] = {
        0xa5, 0x40, 0xb9, 0x45, 0xb8, 0x4c, 0xac, 0x68, 0x88,
        0x66, 0xa2, 0x44, 0x84, 0x52, 0x88, 0x75, 0xbf, 0x64,
        0x88, 0x6e, 0xb3, 0x65, 0xa4, 0x7e, 0xa0, 0x44, 0xa5,
        0x64, 0x88, 0x48, 0x99, 0x7e, 0x8e, 0x4e, 0x82, 0x73,
        0x88, 0x47, 0x96, 0x57, 0xb8, 0x53, 0x88, 0x55, 0xe7,
        0x45, 0xb6, 0x78, 0xaa, 0x00
    };
    unsigned char k;
    unsigned char key[2] = {
        (n1 & 0xff) ^ (n2 & 0xff),
        ((n1 & 0xff00) >> 8) ^ ((n2 & 0xff00) >> 8)
    };
    for (int i = 0; password[i]; i++) {
        k = key[i % 2];
        printf("%c", password[i] ^ k);
    }
    printf("\n");
}

int check_random(int number)
{
    srand(number);
    return number == rand() % 0xffff;
}

int main(int ac, char **av)
{
    if (ac != 3) {
        puts("Usage: ./rand2 <number1> <number2>");
        return 1;
    }

    int n1 = atoi(av[1]);
    int n2 = atoi(av[2]);

    if (check_random(n1) && check_random(n2) && n1 != n2) {
        puts("Success! You got my secret numbers, here is my flag");
        show_flag(n1, n2);
    } else {
        puts("Failed! This is not even close");
    }
    return 0;
}
