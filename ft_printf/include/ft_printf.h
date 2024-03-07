#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

/* ---------- FLAGS ---------- */
typedef struct s_flags
{
	int	spec;
	int	left;
	int	zero;
	int	precision;
	int	width;
	int	star;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

t_flags	ft_flags_init(void);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_precision(const char *str, int i, va_list args,
			t_flags *flags);
int		ft_pad_width(int width, int size, int zero);


/* ---------- SPECs ---------- */
// c
int		ft_print_char(char c, t_flags flags);
int		ft_putchar(char c);
// s
int		ft_print_str(const char *str, t_flags flags);
int		ft_print_precision(const char *str, int precision);
// p

// d, i

// u

// x, X


/* ---------- PRINTF ---------- */
int		ft_printf(const char *format, ...);
int		ft_format(char type, va_list args, t_flags flags);

#endif
