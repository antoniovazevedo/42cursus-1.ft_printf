#include "../includes/ft_printf.h"

static int	ft_hex_len(unsigned long nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static t_string	ft_int_to_hex(unsigned long nb, t_struct *params)
{
	int		len;
	char	*base;
	char	*str;

	if (params->conversion == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = ft_hex_len(nb);
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

t_string	get_hex_string(unsigned long nb, t_struct *params)
{
	if (nb)
		return (ft_int_to_hex(nb, params));
	else if (nb == 0 && params->precision != 0)
		return (ft_strdup("0"));
	return (ft_strdup(""));
}

int	aux_print_alt_format(t_struct *params)
{
	return (aux_print_char('0') + aux_print_char(params->conversion));
}

void	print_hex(t_struct *params, va_list ap)
{
	int				len;
	int				len_w_prec;
	char			*str;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	str = get_hex_string(nb, params);
	len = ft_strlen(str);
	len_w_prec = len;
	if (params->precision > len)
		len_w_prec = params->precision;
	if (params->hash && nb != 0)
		len_w_prec += 2;
	if (params->hash && nb != 0 && params->zero)
		params->g_len += aux_print_alt_format(params);
	if (params->width && !params->minus)
		params->g_len += ft_width(params->width, params->zero, len_w_prec);
	if (params->hash && nb != 0 && !params->zero)
		params->g_len += aux_print_alt_format(params);
	params->g_len += ft_width(params->precision, 1, len);
	params->g_len += aux_print_str(str, len);
	if (params->width && params->minus)
		params->g_len += ft_width(params->width, params->zero, len_w_prec);
	free(str);
}
