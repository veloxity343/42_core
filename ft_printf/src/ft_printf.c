#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;

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

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	int i;

	if (argc > 1)
	{
		i = 1;
		ft_printf("No. args: %d\n", argc);
		printf("No. args: %d\n", argc);
		while (argv[i] != NULL)
		{
			ft_printf("Arg %d: %s\n", i, argv[i]);
			printf("Arg %d: %s\n", i, argv[i]);
			i++;
		}
	}
	return (0);
}*/