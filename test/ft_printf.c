#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void	ft_str(char *str, int *len)
{
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_digit(long nb, int base, int *len)
{
	char	*hex = "0123456789abcdef";

	if (nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if (nb >= base)
		ft_digit((nb / base), base, len);
	*len += write(1, &hex[nb % base], 1);
}

int	ft_printf(const char *format, ... )
{
	int len = 0;

	va_list	ptr;
	va_start(ptr, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				ft_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				ft_digit((long)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				ft_digit((long)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}

/* int main()
{
    char    long_str[10000];
    int     my_count;
    int     og_count;

    memset(long_str, 'A', 9999);
    long_str[9999] = '\0';
    my_count = ft_printf("My:\t%s, %d, %x, %s\n", "Hello, World", INT_MIN, INT_MIN, long_str);
    og_count = printf("OG:\t%s, %d, %x, %s\n", "Hello, World", INT_MIN, INT_MIN, long_str);
    printf("My count:\t%d\nOG count:\t%d\n", my_count, og_count);
} */
