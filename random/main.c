//
//
//

#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
    if (ac != 2)
	return 1;
    srand(atoi(av[1]));
    for (int i = 0; i < 10; i++) {
	printf("%d : 0x%x\n", i, rand() % 0xff);
    }
    return 0;
}
