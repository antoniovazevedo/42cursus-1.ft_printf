#include "../includes/ft_printf.h"

int ft_p_hex_len(unsigned long long nb)
{
	int len;

	len = 1;
	while (nb >= 16)
	{
		len++;
		nb /= 16;
	}

	return (len);
}

string ft_p_to_hex(unsigned long long nb, t_struct *params)
{
	int len;
	char *base;
	char *str;

	if (params->conversion == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = ft_p_hex_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len > 0)
	{
		str[len - 1] = base[nb % 16];
		nb /= 16;
		len--;
	}

	return (str);
}

string get_ptr_str(t_struct *params, va_list ap)
{
	unsigned long long nb;
	char *temp_str;
	char *str;

	nb = (unsigned long long)va_arg(ap, void *);
	temp_str = "";
	if (nb)
		temp_str = ft_p_to_hex(nb, params);
	else if (nb == 0 && params->precision != 0)
		temp_str = "0";
	str = ft_strjoin("0x", temp_str);
	if (nb)
		free(temp_str);
	return (str);
}

void print_ptr(t_struct *params, va_list ap)
{
	int					len;
	int					len_with_precision;
	char				*str;

	len = 0;
	str = get_ptr_str(params, ap);
	len = ft_strlen(str);
	len_with_precision = len;
	if (params->precision > len)
		len_with_precision = params->precision;
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, len_with_precision);
	if (params->precision)
		params->global_len += ft_width(params->precision, 1, len);
	if (str)
		params->global_len += aux_print_str(str, len);
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, len_with_precision);
	free(str);
}