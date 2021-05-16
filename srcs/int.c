#include "../includes/ft_printf.h"
#include <limits.h>

int		get_len_with_precision(int nb, int nb_len, t_struct *params)
{
	if (params->precision > nb_len)
		nb_len = params->precision;
	if (nb < 0)
		nb_len++;
	return (nb_len);
}

char	*nb_to_str(int nb)
{
	char	*str;
	char	*str2;
	char	*str3;

	if (nb == INT_MIN)
	{
		str2 = ft_itoa(INT_MAX / 10);
		str3 = ft_itoa(-(nb % 10));
		str = ft_strjoin(str2, str3);
		free(str2);
		free(str3);
	}
	else if (nb < 0)
		str = ft_itoa(-nb);
	else
		str = ft_itoa(nb);

	return (str);
}

void print_int(t_struct *params, va_list ap)
{
	int nb;
	int nb_len;
	int len_with_precision;
	char *nb_str;

	nb = va_arg(ap, int);
	nb_len = 0;
	nb_str = nb_to_str(nb);
	if (nb != 0 || params->precision != 0)
		nb_len = ft_strlen(nb_str);
	len_with_precision = get_len_with_precision(nb, nb_len, params);
	if (params->plus && nb >= 0)
		params->global_len += aux_print_char('+');
	if (nb < 0 && params->precision == -1 && params->zero)
		params->global_len += aux_print_char('-');
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, len_with_precision);
	if (nb < 0 && (!params->zero || params->precision > -1))
		params->global_len += aux_print_char('-');
	if (params->precision >= 0)
		params->global_len += ft_width(params->precision, 1, nb_len);
	if (nb != 0 || params->precision != 0)
		params->global_len += aux_print_str(nb_str, nb_len);
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, len_with_precision);
	free(nb_str);
}