#include "../includes/ft_printf.h"
#include <stdio.h>

void	write_width(int len, int zero)
{
	while (len > 0)
	{
		if (zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len--;
	}
}

int ft_width(int width, int zero, int str_len)
{
	int printed_char_count;

	printed_char_count = 0;
	while (printed_char_count + str_len < width)
	{
		if (zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		printed_char_count++;
	}
	return printed_char_count;
}

void debug_params(t_struct *params)
{
	printf("\n-----------------------\n");
	printf("\tconversion: \t%c\n", params->conversion);
	printf("\tminus: \t\t%d\n", params->minus);
	printf("\tplus: \t\t%d\n", params->plus);
	printf("\tzero: \t\t%d\n", params->zero);
	printf("\tspace: \t\t%d\n", params->space);
	printf("\thash: \t\t%d\n", params->hash);
	printf("\twidth: \t\t%d\n", params->width);
	printf("\tprecision: \t%d\n", params->precision);
	printf("\tstr_len: \t%d\n", params->str_len);
	printf("\tglobal_len: \t%d\n", params->global_len);
	printf("\n-----------------------\n");

}

void reset_params(t_struct *params)
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
}

void format(char conversion, va_list ap, t_struct *params)
{
	// 	debug_params(params);
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
}

void parse_flags(const char *str, t_struct *params)
{
	while (ft_strchr(FLAG_SYMBOLS, *str))
	{
		if (*str == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		else if (*str == '+')
			params->plus = 1;
		else if (*str == '0' && !params->minus)
			params->zero = 1;
		else if (*str == ' ')
			params->space = 1;
		else if (*str == '#')
			params->hash = 1;
		str++;
	}
}

void parse_width(const char *str, va_list ap, t_struct *params)
{
	int		i;
	int		start;
	char	*sub;

	i = 0;
	start = 0;
	while (ft_strchr(FLAG_SYMBOLS, str[i]))
		i++;
	start = i;
	if (str[i] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->minus = 1;
			params->zero = 0;
			params->width = -params->width;
		}
		return;
	}
	while (ft_strchr("0123456789", str[i]))
		i++;
	sub = ft_substr(str, start, i - start);
	params->width = ft_atoi(sub);
	free(sub);
}

void parse_precision(const char *str, va_list ap, t_struct *params)
{
	int		i;
	int		start;
	char	*sub;

	i = 0;
	start = 0;
	while (ft_strchr(FLAG_SYMBOLS, str[i]) || ft_strchr("*0123456789", str[i]))
		i++;
	if (str[i] != '.')
		return;
	start = i + 1;
	if (str[start] == '*')
	{
		params->precision = va_arg(ap, int);
		return;
	}
	while (!ft_strchr(CONVERSION_SYMBOLS, str[i]))
		i++;
	sub = ft_substr(str, start, i - start);
	params->precision = ft_atoi(sub);
	free(sub);
}

void parse_modifiers(const char *str, va_list ap, t_struct *params)
{
	parse_flags(str, params);
	parse_width(str, ap, params);
	parse_precision(str, ap, params);

	if (params->conversion != 's' &&
		params->conversion != 'c' && 
		params->precision > -1)
		params->zero = 0;	
}

char parse_conversion(const char *str, t_struct *params)
{
	int len;
	char *conversion;

	len = 0;
	conversion = NULL;
	while (ft_strchr(FLAG_SYMBOLS, *str) ||
		   ft_strchr(PRECISION_SYMBOLS, *str) ||
		   ft_strchr(CONVERSION_SYMBOLS, *str))
	{
		len++;
		conversion = ft_strchr(CONVERSION_SYMBOLS, *str);
		if (conversion)
			break;
		str++;
	}

	if (conversion)
		params->conversion = conversion[0];
	return (len);
}

int parse(const char *str, va_list ap, t_struct *params)
{
	int len;

	reset_params(params);
	len = parse_conversion(str, params);
	if (!params->conversion)
		return (0);
	parse_modifiers(str, ap, params);
	format(params->conversion, ap, params);
	return (len);
}

int ft_printf(const char *str, ...)
 {
	int			i;
	va_list 	ap;
	t_struct	*params;
	int			len;

	i = 0;
	va_start(ap, str);
	params = (t_struct *)malloc(sizeof(t_struct));
	if (!params)
		return (0);
	reset_params(params);
	params->global_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += parse(&str[i + 1], ap, params) + 1;
		else
		{
			ft_putchar_fd(str[i++], 1);
			params->global_len++;
		}
	}
	va_end(ap);
	len = params->global_len;
	free(params);

	return (len);
}