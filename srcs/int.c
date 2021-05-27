#include "../includes/ft_printf.h"
#include <limits.h>

// static int	get_len_w_precision(int nb, int nb_len, t_struct *params)
// {
// 	if (params->precision > nb_len)
// 		nb_len = params->precision;
// 	if (nb < 0)
// 		nb_len++;
// 	return (nb_len);
// }

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

// static int	aux_print_plus_or_space(t_struct *params, int nb)
// {
// 	int	ret;

// 	ret = 0;
// 	if (params->plus && nb >= 0)
// 		ret = aux_print_char('+');
// 	else if (params->space && nb >= 0)
// 		ret = aux_print_char(' ');
// 	params->global_len += ret;
// 	return (ret);
// }

void	print_int(t_struct *params, va_list ap)
{
	int		nb;
	int		nb_len;
	char	*nb_str;
	int		padding_left;

	nb = va_arg(ap, int);
	nb_str = nb_to_str(nb);
	nb_len = 0;
	padding_left = 0;

	if (nb != 0 || params->precision != 0)
		nb_len = ft_strlen(nb_str);

	if (params->precision > nb_len)
		padding_left = params->precision - nb_len;

	if (nb < 0)
		nb_len++;

	if (nb < 0 && params->zero)
		aux_print_char('-');

	if (!params->minus && params->width > padding_left + nb_len)
		params->global_len += ft_width(params->width, params->zero, padding_left + nb_len);

	if (nb < 0 && !params->zero)
		aux_print_char('-');
	
	int i;
	i = 0;
	while (i++ < padding_left)
		params->global_len += aux_print_char('0');
	
	if (nb != 0 || params->precision != 0)
	params->global_len += aux_print_str(nb_str, nb_len);

	if (params->minus && params->width > padding_left + nb_len)
		params->global_len += ft_width(params->width, params->zero, padding_left + nb_len);

	free(nb_str);
}
