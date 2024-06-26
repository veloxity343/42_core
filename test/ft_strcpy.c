char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

/* #include <stdio.h>

int main(int ac, char *av[])
{
    if (ac == 3)
    {
        char *s1 = av[1];
        char *s2 = av[2];

        char *res = ft_strcpy(s1, s2);
        printf("%s\n%s\n%s\n", res, s1, s2);
        return (0);
    }
} */