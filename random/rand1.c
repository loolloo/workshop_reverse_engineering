//
// rand1.c
//

#include <stdio.h>
#include <stdlib.h>

void show_flag(int n)
{
    unsigned char password[] = {
        0x93, 0x06, 0x90, 0x70, 0x8e, 0x0a, 0x85,
        0x5d, 0x87, 0x38, 0xa7, 0x7b, 0xb4, 0x38,
        0x95, 0x5a, 0xd1, 0x10, 0xa1, 0x40, 0x89,
        0x22, 0xa1, 0x67, 0x84, 0x22, 0x9a, 0x4b,
        0x98, 0x08, 0xab, 0x4b, 0x8a, 0x09, 0xce,
        0x63, 0xbe, 0x22, 0x88, 0x71, 0xb3, 0x1e,
        0xaa, 0x7c, 0x88, 0x09, 0xb9, 0x69, 0x00
    };
    unsigned char k;
    unsigned char key[4] = {
        n & 0xff,
        (n & 0xff00)     >> 8,
        (n & 0xff0000)   >> 16,
        (n & 0xff000000) >> 24
    };
    for (int i = 0; password[i]; i++) {
        k = key[i % 4];
        printf("%c", password[i] ^ k);
    }
    printf("\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        puts("Usage: ./rand1 <number>");
        return 1;
    }

    srand(0xdeadbeef);
    int n = atoi(av[1]);
    if (n == rand() & 0xffffffff) {
        puts("Success! You figured out my secret number");
        show_flag(n);
    } else {
        puts("Failed! Try your luck next time!");
    }
    return 0;
}
