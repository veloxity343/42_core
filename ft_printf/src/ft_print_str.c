#include "ft_printf.h"

int	ft_print_precision(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

static int	ft_pad_string(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_pad_width(flags.precision, ft_strlen(str), 0);
		count += ft_print_precision(str, flags.precision);
	}
	else
		count += ft_print_precision(str, ft_strlen(str));
	return (count);
}

int	ft_print_str(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "NULL";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		count += ft_pad_string(str, flags);
	if (flags.precision >= 0)
		count += ft_pad_width(flags.width, flags.precision, 0);
	else
		count += ft_pad_width(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		count += ft_pad_string(str, flags);
	return (count);
}
