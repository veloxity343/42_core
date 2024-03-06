#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	left;
	int	zero;
	int	precision;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	star;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_format(char type, va_list args, t_flags flags);

/* ---------- CONVERSION SPECIFIERS ---------- */
// c
int		ft_print_char(char c, t_flags flags);
int		ft_putchar(char c);
// s

#endif
