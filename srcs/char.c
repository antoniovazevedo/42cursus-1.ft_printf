#include "../includes/ft_printf.h"

void	print_char(t_struct *params, va_list ap)
{
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, 1);
	ft_putchar_fd(va_arg(ap, int), 1);
	params->global_len += 1;
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, 1);
}

void	print_percent(t_struct *params)
{
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, 1);
	ft_putchar_fd('%', 1);
	params->global_len += 1;
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, 1);
}
