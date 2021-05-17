#include "../includes/ft_printf.h"
#include <limits.h>

static int	get_len_w_precision(int nb, int nb_len, t_struct *params)
{
	if (params->precision > nb_len)
		nb_len = params->precision;
	if (nb < 0)
		nb_len++;
	return (nb_len);
}

static char	*nb_to_str(int nb)
{
	char	*str;
	char	*str2;
	char	*str3;
	int		nb_aux;

	if (nb == INT_MIN)
	{
		str2 = ft_itoa(INT_MAX / 10);
		nb_aux = - (nb % 10);
		str3 = ft_itoa(nb_aux);
		str = ft_strjoin(str2, str3);
		free(str2);
		free(str3);
		return (str);
	}
	else if (nb < 0)
		return (ft_itoa(-nb));
	return (ft_itoa(nb));
}

static int	aux_print_plus_or_space(t_struct *params, int nb)
{
	int	ret;

	ret = 0;
	if (params->plus && nb >= 0)
		ret = aux_print_char('+');
	else if (params->space && nb >= 0)
		ret = aux_print_char(' ');
	params->global_len += ret;
	return (ret);
}

void	print_int(t_struct *params, va_list ap)
{
	int		nb;
	int		nb_len;
	int		len_w_prec;
	char	*nb_str;

	nb = va_arg(ap, int);
	nb_len = 0;
	nb_str = nb_to_str(nb);
	if (nb != 0 || params->precision != 0)
		nb_len = ft_strlen(nb_str);
	len_w_prec = get_len_w_precision(nb, nb_len, params);
	len_w_prec += aux_print_plus_or_space(params, nb);
	if (nb < 0 && params->precision == -1 && params->zero)
		params->global_len += aux_print_char('-');
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, len_w_prec);
	if (nb < 0 && (!params->zero || params->precision > -1))
		params->global_len += aux_print_char('-');
	if (params->precision >= 0)
		params->global_len += ft_width(params->precision, 1, nb_len);
	if (nb != 0 || params->precision != 0)
		params->global_len += aux_print_str(nb_str, nb_len);
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, len_w_prec);
	free(nb_str);
}
