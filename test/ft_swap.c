void	ft_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

#include <stdio.h>

int main()
{
    int a = 75;
    int b = 25;

    ft_swap(&a, &b);
    printf("a = %d\nb = %d\n", a, b);
    return (0);
}