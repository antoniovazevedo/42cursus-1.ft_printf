#include "../includes/ft_printf.h"

void print_pointer(t_struct *params, va_list ap)
{
	print_hex(params, ap);
}