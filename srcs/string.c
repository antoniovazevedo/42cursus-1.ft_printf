#include "../includes/ft_printf.h"

void	print_string(t_struct *params, va_list ap)
{
	char	*str;
	char	*substr;
	int		len;

	str = va_arg(ap, char *);
	substr = NULL;
	len = 0;
	if (!str)
		str = "(null)";
	if (params->precision > -1)
	{
		substr = ft_substr(str, 0, params->precision);
		str = substr;
	}
	if (str)
		len = ft_strlen(str);
	if (params->width && !params->minus)
		params->global_len += ft_width(params->width, params->zero, len);
	if (str)
		ft_putstr_fd(str, 1);
	params->global_len += len;
	if (params->width && params->minus)
		params->global_len += ft_width(params->width, params->zero, len);
	if (substr)
		free(substr);
}
