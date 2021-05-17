#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int ret2;
	int n;
	int n2;
	char *str = "%20s %n %.3i";

	ret = printf(str, "meow", &n, 23);
	printf("\nn=%i\n", n);
	printf("\nret=%i\n\n", ret);
	ret2 = ft_printf(str, "meow", &n2, 23);
	printf("\nn=%i\n", n2);
	printf("\nret=%i\n\n", ret2);
}