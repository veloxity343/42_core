#include "get_next_line.h"

char *ft_strchr(char *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return (str);
        str++;
    }
    return (NULL);
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    
    while (str[i])
        i++;
    return (i);
}

void ft_strcpy(char *dst, const char *src)
{
    while (*src)
        *dst++ = *src++;
    *dst = '\0';
}

char *ft_strdup(const char *src)
{
    size_t len = ft_strlen(src) + 1;
    char *dst = malloc(len);

    if (dst == NULL)
        return (NULL);
    ft_strcpy(dst, src);
    return (dst);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *join;

    if (!s1 || !s2)
        return (NULL);
    join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!join)
    {
        free(s1);
        return (NULL);
    }
    ft_strcpy(join, s1);
    ft_strcpy(join + ft_strlen(s1), s2);
    free(s1);
    return (join);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    char *new_line;
    int count;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);

    line = ft_strdup(buffer);
    if (!line)
        return (NULL);

    while (!(new_line = ft_strchr(line, '\n')) && (count = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[count] = '\0';
        line = ft_strjoin(line, buffer);
        if (!line)
            return (NULL);
    }
    if (ft_strlen(line) == 0)
        return (free(line), NULL);
    if (new_line)
    {
        ft_strcpy(buffer, new_line + 1);
        *(new_line + 1) = '\0';
    }
    else
        buffer[0] = '\0';
    return (line);
}
