#include "../includes/ft_printf.h"
#include <limits.h>

static int	unsigned_len_w_prec(unsigned int nb, int nb_len, t_struct *params)
{
	if (params->precision > nb_len)
		nb_len = params->precision;
	if (nb < 0)
		nb_len++;
	return (nb_len);
}

static char	*unsigned_nb_to_str(unsigned int nb)
{
	if (nb < 0)
		return (ft_uitoa(-nb));
	return (ft_uitoa(nb));
}

void	print_unsigned_int(t_struct *params, va_list ap)
{
	unsigned int	nb;
	int				nb_len;
	int				len_w_prec;
	char			*nb_str;

	nb = va_arg(ap, unsigned int);
	nb_len = 0;
	nb_str = unsigned_nb_to_str(nb);
	if (nb != 0 || params->precision != 0)
		nb_len = ft_strlen(nb_str);
	len_w_prec = unsigned_len_w_prec(nb, nb_len, params);
	if (params->plus && nb >= 0)
		params->global_len += aux_print_char('+');
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
