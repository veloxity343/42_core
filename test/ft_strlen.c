int ft_strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

/* #include <stdio.h>

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        char *str = av[1];
        
        int res = ft_strlen(str);
        printf("%d\n", res);
        return (0);
    }
} */