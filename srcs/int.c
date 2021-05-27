#include "../includes/ft_printf.h"
#include <limits.h>

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

void	print_int_do(int nb, int nb_len, char *nb_str, t_struct *params)
{
	int		pad;
	int		has_width;

	pad = 0;
	if (params->precision > nb_len)
		pad = params->precision - nb_len;
	nb_len += (nb < 0 || params->plus || params->space);
	if (nb < 0 && params->zero)
		params->g_len += aux_print_char('-');
	has_width = params->width > pad + nb_len;
	if (has_width && params->zero)
		params->g_len += aux_print_plus_or_space(params, nb);
	if (!params->minus && has_width)
		params->g_len += ft_width(params->width, params->zero, pad + nb_len);
	if (nb < 0 && !params->zero)
		params->g_len += aux_print_char('-');
	else if ((!has_width || !params->zero) && (params->plus || params->space))
		params->g_len += aux_print_plus_or_space(params, nb);
	params->g_len += ft_width(pad, 1, 0);
	if (nb != 0 || params->precision != 0)
		params->g_len += aux_print_str(nb_str, ft_strlen(nb_str));
	if (params->minus && params->width > pad + nb_len)
		params->g_len += ft_width(params->width, params->zero, pad + nb_len);
}

void	print_int(t_struct *params, va_list ap)
{
	int		nb;
	int		nb_len;
	char	*nb_str;

	nb = va_arg(ap, int);
	nb_len = 0;
	nb_str = nb_to_str(nb);
	if (nb != 0 || params->precision != 0)
		nb_len = ft_strlen(nb_str);
	print_int_do(nb, nb_len, nb_str, params);
	free(nb_str);
}
