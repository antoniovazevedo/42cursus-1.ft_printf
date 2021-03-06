#include "../includes/ft_printf.h"

static int	ft_p_hex_len(unsigned long long nb)
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

static t_string	ft_p_to_hex(unsigned long long nb, t_struct *params)
{
	int		len;
	char	*base;
	char	*str;

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

static t_string	get_ptr_str(t_struct *params, va_list ap)
{
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(ap, void *);
	if (nb)
		return (ft_p_to_hex(nb, params));
	else if (nb == 0 && params->precision != 0)
		return (ft_strdup("0"));
	return (ft_strdup(""));
}

void	print_ptr(t_struct *params, va_list ap)
{
	int					len;
	int					len_w_prec;
	char				*str;

	len = 0;
	str = get_ptr_str(params, ap);
	len = ft_strlen(str);
	len_w_prec = len;
	if (params->precision > len)
		len_w_prec = params->precision;
	if (params->width && !params->minus)
		params->g_len += ft_width(params->width, params->zero, len_w_prec + 2);
	ft_putstr_fd("0x", 1);
	params->g_len += 2;
	if (params->precision)
		params->g_len += ft_width(params->precision, 1, len);
	if (str)
		params->g_len += aux_print_str(str, len);
	if (params->width && params->minus)
		params->g_len += ft_width(params->width, params->zero, len_w_prec + 2);
	free(str);
}
