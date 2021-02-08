//
// solve3.c
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ranges[] = {
        0x30000000,
        0x80000000,
        0x90000000,
	0xe0000000
    };

    for (int r = 0; r < 4; r++) {
        for (unsigned int i = ranges[r]; i < ranges[r] + 0x10000000; i++) {
            srand(i);
            if (!(int)rand()) {
                printf("%d %p\n", i, i);
                break;
            }
        }
    }
    printf("Done!");
    return 0;
}
