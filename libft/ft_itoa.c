#include "libft.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	convert_to_string(char *str, int n, int num_digits, int is_negative)
{
	str[num_digits] = '\0';
	while (n > 0)
	{
		str[--num_digits] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int num_digits;
	char *result;
	int is_negative;

	num_digits = count_digits(n);
	result = (char *)malloc((num_digits + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
		num_digits++;
	}
	convert_to_string(result, n, num_digits, is_negative);
	return (result);
}