#include "../includes/ft_printf.h"

int		aux_print_str(char *str, int len)
{
	ft_putstr_fd(str, 1);
	return (len);
}

int		aux_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
