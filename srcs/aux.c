#include "../includes/ft_printf.h"

int	ft_width(int width, int zero, int str_len)
{
	int	printed_char_count;

	printed_char_count = 0;
	while (printed_char_count + str_len < width)
	{
		if (zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		printed_char_count++;
	}
	return (printed_char_count);
}

int	aux_print_str(char *str, int len)
{
	ft_putstr_fd(str, 1);
	return (len);
}

int	aux_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
