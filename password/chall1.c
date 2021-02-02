//
// chall1
//

#include <stdio.h>
#include <string.h>
#include <stddef.h>

wchar_t password[] = L"passwd{If_your_password_is_too_short_just_make_it_wider!}";

int cmp_wide_str(char *input)
{
    int i;
    for (i = 0; password[i] == input[i] && input[i]; i++);
    return password[i] - input[i];
}

int main(int ac, char **av)
{
    if (ac != 2) {
	puts("Usage: ./chall1 <password>");
	return 1;
    }

    if (cmp_wide_str(av[1]) == 0)
	puts("Success you can use this as the flag");
    else
	puts("Failed... Try again!");

    return 0;
}
