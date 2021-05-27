#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define	CONVERSION_SYMBOLS "cspdiuxXnfge%"
# define FLAG_SYMBOLS "-+ 0#"
# define PRECISION_SYMBOLS ".0123456789*"

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_struct
{
	char		conversion;
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			hash;
	int			width;
	int			precision;
	int			str_len;
	int			g_len;
}				t_struct;

typedef char*	t_string;

int		ft_printf(const char *str, ...);
int		ft_width(int width, int zero, int str_len);
void	print_int(t_struct *params, va_list ap);
void	print_unsigned_int(t_struct *params, va_list ap);
void	print_string(t_struct *params, va_list ap);
void	print_char(t_struct *params, va_list ap);
void	print_percent(t_struct *params);
void	print_hex(t_struct *params, va_list ap);
void	print_ptr(t_struct *params, va_list ap);
int		aux_print_str(char *str, int len);
int		aux_print_char(char c);
void	parse_modifiers(const char *str, va_list ap, t_struct *params);
char	parse_conversion(const char *str, t_struct *params);

#endif