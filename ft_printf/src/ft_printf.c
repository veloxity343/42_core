#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	else if (type == 's')
		count += ft_print_str(va_arg(args, const char *), flags);
	else if (type == 'p')
		count += ft_print_ptr((unsigned long int)va_arg(args, void *), flags);
	else if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(args, int), flags);
	else if (type == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), flags);
	else if (type == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0, flags);
	else if (type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1, flags);
	else if (type == '%')
		count += ft_print_char('%', flags);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	char *str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str)
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	free(str);
	return (count);
}
