#include "../includes/ft_printf.h"
#include <limits.h>

static char	*unsigned_nb_to_str(unsigned int nb)
{
	if (nb < 0)
		return (ft_uitoa(-nb));
	return (ft_uitoa(nb));
}

void	print_u_int_do(unsigned int nb, int len, char *nb_str, t_struct *params)
{
	int		pad;
	int		has_width;

	pad = 0;
	if (params->precision > len)
		pad = params->precision - len;
	len += (nb < 0 || params->plus || params->space);
	if (nb < 0 && params->zero)
		aux_print_char('-');
	has_width = params->width > pad + len;
	if (has_width && params->zero)
		params->g_len += aux_print_plus_or_space(params, nb);
	if (!params->minus && has_width)
		params->g_len += ft_width(params->width, params->zero, pad + len);
	if (nb < 0 && !params->zero)
		aux_print_char('-');
	else if ((!has_width || !params->zero) && (params->plus || params->space))
		params->g_len += aux_print_plus_or_space(params, nb);
	params->g_len += ft_width(pad, 1, 0);
	if (nb != 0 || params->precision != 0)
		params->g_len += aux_print_str(nb_str, len);
	if (params->minus && params->width > pad + len)
		params->g_len += ft_width(params->width, params->zero, pad + len);
}

void	print_unsigned_int(t_struct *params, va_list ap)
{
	unsigned int	nb;
	int				len;
	char			*nb_str;

	nb = va_arg(ap, unsigned int);
	len = 0;
	nb_str = unsigned_nb_to_str(nb);
	if (nb != 0 || params->precision != 0)
		len = ft_strlen(nb_str);
	print_u_int_do(nb, len, nb_str, params);
	free(nb_str);
}
