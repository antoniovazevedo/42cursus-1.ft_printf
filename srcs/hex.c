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

void	print_hex(t_struct *params, va_list ap)
{
	int				len;
	int				len_w_prec;
	char			*str;
	unsigned int	nb;
	char *af;

	nb = va_arg(ap, unsigned int);
	str = get_hex_string(nb, params);
	len = ft_strlen(str);
	len_w_prec = len;
	if (params->precision > len)
		len_w_prec = params->precision;

	af = "0x";
	if (params->conversion == 'X')
		af = "0X";


	if (params->hash && nb != 0)
		len_w_prec += 2;

	if (params->hash && nb != 0 && params->zero)
		params->global_len += aux_print_str(af, 2);
		
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, len_w_prec);

	if (params->hash && nb != 0 && !params->zero)
		params->global_len += aux_print_str(af, 2);
		
	if (params->precision)
		params->global_len += ft_width(params->precision, 1, len);
	if (str)
		params->global_len += aux_print_str(str, len);
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, len_w_prec);
	free(str);
}
