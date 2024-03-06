#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.left == 1)
		count += ft_putchar(c);
	count += ft_pad_width(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += ft_putchar(c);
	return (count);
}
