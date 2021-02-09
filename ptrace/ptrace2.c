//
// ptrace2.c
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
//     return (out & 0xff00ffff) | (c << 16);
// }

unsigned char decrypt_char(unsigned int inp)
{
    char out = 42;

    for (unsigned int i = 0; i < (inp % 100); i++) {
        out += i ^ out;
        out = (out * out) % 0xff;
    }
    return (unsigned char)((inp & 0x00ff0000) >> 16);
}

void get_password(char *password)
{
    int store[] = {
        0xec48d891, 0x4d65da98, 0x5268fb51, 0x4d65da98, 0xc55f6140,
        0xc9439788, 0x6761e4c0, 0x746e2969, 0x746e2969, 0x173019a1,
        0x95744bd9, 0xcb2d9d68, 0xec48d891, 0x6761e4c0, 0x746e2969,
        0xa4641479, 0x686c0b19, 0x94458458, 0xc55f6140, 0x7d541ad9,
        0x5268fb51, 0x94458458, 0xc55f6140, 0xad50fd21, 0x7d541ad9,
        0x8f72e4e1, 0x86415080, 0x6d637c48, 0x4d65da98, 0xcb2d9d68,
        0xcc49e5d0, 0xd66a3c9, 0xc55f6140, 0x2259fef0, 0x866f6c20,
        0x11558578, 0xcb2d9d68, 0xc9439788, 0x6761e4c0, 0x746e2969,
        0x7d541ad9, 0xc55f6140, 0x1a536168, 0x4d65da98, 0x4d65da98,
        0xc55f6140, 0xdf692810, 0x7d541ad9, 0xc55f6140, 0xe55688c9,
        0xdf692810, 0x6d637c48, 0x7d541ad9, 0x173019a1, 0x8f72e4e1,
        0x2259fef0, 0xc55f6140, 0xcc49e5d0, 0x9a73b5a8, 0xc55f6140,
        0xc54d08a8, 0xdf692810, 0x746e2969, 0x94458458, 0x29219440,
        0x29219440, 0 };
    for (int i = 0; store[i]; i++) {
        password[i] = decrypt_char(store[i]);
        password[i + 1] = 0;
    }
}

void __attribute__((constructor)) sanity_check()
{
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        puts("The usage of any debugger is prohibited for this program lol");
        exit(1);
    }
}

int main(int ac, char **av)
{
    char password[100];

    if (ac != 2) {
        puts("Usage: ./ptrace2 <password>");
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
