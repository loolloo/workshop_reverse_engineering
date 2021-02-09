//
// ptrace1.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

// unsigned int encrypt_char(unsigned char c)
// {
//     unsigned int out = 42;
// 
//     for (unsigned char i = 1; i < c; i++) {
//         out += i ^ out;
//         out *= i;
//     }
//     return (out << 8) | c;
// }

unsigned char decrypt_char(unsigned int inp)
{
    char out = 42;

    for (unsigned int i = 0; i < (inp % 100); i++) {
        out += i ^ out;
        out = (out * out) % 0xff;
    }
    return (unsigned char)(inp & 0xff);
}

void get_password(char *password)
{
    int store[] = {
        0x15d89148, 0x5fda9865, 0x320b196c, 0x320b196c, 0xef6fe04f,
        0x7f61405f, 0xf1ad954, 0x4dfb5168, 0x6c845845, 0x45e4e172,
        0x5fda9865, 0x7f61405f, 0x49e5d049, 0x569d682d, 0x15d89148,
        0x7219a130, 0x7d82170, 0x5fda9865, 0x7f61405f, 0x2dfef059,
        0xfb6c206f, 0x8ca8b875, 0x7f61405f, 0x1762b944, 0x5c281069,
        0x3a147964, 0xfa29696e, 0xf1ad954, 0x7f61405f, 0x9b321047,
        0xfb6c206f, 0x7f61405f, 0xf1ad954, 0x4dfb5168, 0x45e4e172,
        0xfb6c206f, 0x8ca8b875, 0x9b321047, 0x15d89148, 0x569d682d,
        0xf1ad954, 0x4dfb5168, 0x5c281069, 0xf8616853, 0x569d682d,
        0x6c845845, 0xfa29696e, 0x6f7c4863, 0x45e4e172, 0x2dfef059,
        0x7d82170, 0x3d4bd974, 0x5c281069, 0xfb6c206f, 0xfa29696e,
        0x7f61405f, 0xd4f18142, 0x97593079, 0x7f61405f, 0x15d89148,
        0x98e4c061, 0xfa29696e, 0x3a147964, 0xea944021, 0 };
    for (int i = 0; store[i]; i++) {
	password[i] = decrypt_char(store[i]);
	password[i + 1] = 0;
    }
}

int main(int ac, char **av)
{
    char password[100];

    if (ac != 2) {
        puts("Usage: ./ptrace1 <password>");
        return 1;
    }
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        puts("Hey! Using a debugger for this program is prohibited >:(");
        return 1;
    }
    get_password(password);
    if (strcmp(password, av[1]) == 0) {
        printf("Success! Here is your flag : ptrace{%s}\n", av[1]);
    } else {
        puts("Failed! Try again :p");
    }
    return 0;
}
