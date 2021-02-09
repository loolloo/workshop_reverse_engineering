//
// solve.c
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 0; i < 0xffff; i++) {
	srand(i);
	if (rand() % 0xffff == i)
	    printf("Here I got it %p %d\n", i, i);
    }
    return 0;
}
