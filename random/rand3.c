//
// rand3.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_flag(int n)
{
    unsigned char password[] = {
        0x86, 0x54, 0x96, 0xf7, 0x9b, 0x58, 0x83,
        0xc4, 0x9c, 0x7a, 0xa7, 0xe7, 0xb2, 0x6a,
        0xac, 0xfb, 0xbb, 0x40, 0x9f, 0xfb, 0xa0,
        0x6a, 0xbd, 0xfd, 0xb7, 0x47, 0xa1, 0xe3,
        0x80, 0x7c, 0x96, 0xf4, 0xab, 0x61, 0x90,
        0xd6, 0xab, 0x66, 0x9d, 0xf6, 0xb0, 0x6a,
        0x8f, 0xd2, 0x87, 0x6a, 0xb9, 0xcc, 0xb3,
        0x05, 0xc8, 0xf7, 0xab, 0x7c, 0x9c, 0xf6,
        0xb5, 0x0a, 0x85, 0x00
    }; // "random{WhO_tF_ThOughT_EnCrYptIng_ThE_SeeD_wAs_A_G00d_IdeA?}";
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

/*
** 0x 30 2e 8c 96
** 0x 85 47 6c f1
** 0x 93 f8 35 f4
** 0x ec c3 1a 74
*/

unsigned char char_to_byte(char c)
{
    switch (c) {
    case 'B': return 0x6c;
    case 'F': return 0x30;
    case 'S': return 0xf1;
    case 'U': return 0xf8;
    case 'R': return 0xc3;
    case 'K': return 0x35;
    case 'N': return 0x93;
    case 'O': return 0x1a;
    case 'L': return 0x2e;
    case 'P': return 0xec;
    case 'G': return 0x96;
    case 'D': return 0x85;
    case 'E': return 0xf4;
    default: break;
    }
    return 0x42;
}

unsigned int input_to_seed(char *input)
{
    char c;
    int bytes[] = {
	0,
	0,
	0,
	0
    };

    if (strlen(input) < 4)
	return 0x01020304;

    for (int i = 0; i < 4; i++) {
	c = input[i];
	if (c < 'A' || c > 'Z') {
	    puts("<seed> must be a string of uppercased letters in the range A-Z");
	    exit(1);
	}
	bytes[i] = char_to_byte(c);
    }
    return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

int main(int ac, char **av)
{
    if (ac != 2) {
	puts("Usage: ./rand3 <seed> # seed is a string of uppercased letters");
	return 1;
    }

    int n = input_to_seed(av[1]);
    srand(n);
    if (!(int)rand()) {
        puts("Success! You figured out my secret number");
	show_flag(n);
    } else {
        puts("Failed! Try your luck next time!");
    }
    return 0;
}
