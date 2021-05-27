#include "../includes/ft_printf.h"

int abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	parse_flags(const char *str, t_struct *params)
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

static void	parse_width(const char *str, va_list ap, t_struct *params)
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
		return ;
	}
	while (ft_strchr("0123456789", str[i]))
		i++;
	sub = ft_substr(str, start, i - start);
	params->width = ft_atoi(sub);
	free(sub);
}

static void	parse_precision(const char *str, va_list ap, t_struct *params)
{
	int		i;
	int		start;
	char	*sub;

	i = 0;
	start = 0;
	while (ft_strchr(FLAG_SYMBOLS, str[i]) || ft_strchr("*0123456789", str[i]))
		i++;
	if (str[i] != '.')
		return ;
	start = i + 1;
	if (str[start] == '*')
		params->precision = va_arg(ap, int);
	else
	{
		while (!ft_strchr(CONVERSION_SYMBOLS, str[i]))
			i++;
		sub = ft_substr(str, start, i - start);
		params->precision = ft_atoi(sub);
		free(sub);
	}

	// if (params->precision > params->width)
	// {
	// 	params->width = 0;
	// 	return;
	// }
	if (params->precision < -1)
		params->precision = -1;

	// if (abs(params->precision) > params->width)
	// 	params->precision = -1;
	
}

void	parse_modifiers(const char *str, va_list ap, t_struct *params)
{
	parse_flags(str, params);
	parse_width(str, ap, params);
	parse_precision(str, ap, params);
	if (params->conversion != 's'
		&& params->conversion != 'c'
		&& !params->minus
		&& params->precision > -1)
		params->zero = 0;
	
	// if (params->width && params->precision > -1 && params->minus)
	// 	params->width = 0;
}

char	parse_conversion(const char *str, t_struct *params)
{
	int		len;
	char	*conversion;

	len = 0;
	conversion = NULL;
	while (ft_strchr(FLAG_SYMBOLS, *str)
		   || ft_strchr(PRECISION_SYMBOLS, *str)
		   || ft_strchr(CONVERSION_SYMBOLS, *str))
	{
		len++;
		conversion = ft_strchr(CONVERSION_SYMBOLS, *str);
		if (conversion)
			break ;
		str++;
	}
	if (conversion)
		params->conversion = conversion[0];
	return (len);
}
