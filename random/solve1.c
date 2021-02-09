//
// rand1.c
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(0xdeadbeef);
    printf("%d\n", rand());
    return 0;
}
