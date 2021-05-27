#include "../includes/ft_printf.h"
#include <stdio.h>

static void	reset_params(t_struct *params, int inc_g_len)
{
	params->conversion = 0;
	params->minus = 0;
	params->plus = 0;
	params->zero = 0;
	params->space = 0;
	params->hash = 0;
	params->width = 0;
	params->precision = -1;
	params->str_len = 0;
	if (inc_g_len == 1)
		params->g_len = 0;
}

static void	handle_n_conversion(t_struct *params, va_list ap)
{
	int	*ptr;

	ptr = va_arg(ap, int *);
	*ptr = params->g_len;
}

static void	format(char conversion, va_list ap, t_struct *params)
{
	if (conversion == '%')
		print_percent(params);
	else if (conversion == 'c')
		print_char(params, ap);
	else if (conversion == '%')
		print_char(params, ap);
	else if (conversion == 's')
		print_string(params, ap);
	else if (conversion == 'd' || conversion == 'i')
		print_int(params, ap);
	else if (conversion == 'u')
		print_unsigned_int(params, ap);
	else if (conversion == 'x' || conversion == 'X')
		print_hex(params, ap);
	else if (conversion == 'p')
		print_ptr(params, ap);
	else if (conversion == 'n')
		handle_n_conversion(params, ap);
}

static int	parse(const char *str, va_list ap, t_struct *params)
{
	int	len;

	reset_params(params, 0);
	len = parse_conversion(str, params);
	if (!params->conversion)
		return (0);
	parse_modifiers(str, ap, params);
	format(params->conversion, ap, params);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	t_struct	*params;
	int			len;

	i = 0;
	va_start(ap, str);
	params = (t_struct *)malloc(sizeof(t_struct));
	if (!params)
		return (0);
	reset_params(params, 1);
	while (str[i])
	{
		if (str[i] == '%')
			i += parse(&str[i + 1], ap, params) + 1;
		else
		{
			ft_putchar_fd(str[i++], 1);
			params->g_len++;
		}
	}
	va_end(ap);
	len = params->g_len;
	free(params);
	return (len);
}
