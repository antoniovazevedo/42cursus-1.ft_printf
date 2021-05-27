#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ret;
	int ret2;

	/*
	a=4	b=-2
	-012 [4]
	012 [3]

	a=3	b=-2
	-12 [3]
	12 [2]

	a=2	b=-2
	-12 [3]
	12 [2]

	a=1	b=-2
	-12 [3]
	12 [2]

	a=0	b=-2
	-12 [3]
	12 [2]
	*/


	char *str = "<%+.7d>";
	// char *str = "<%+10d>";
	// char *str = "<%+05i>";

	printf(str, 234);
	printf("\n");

	ft_printf(str, 234);
	printf("\n\n");
	return 0;
}