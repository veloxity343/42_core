#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

/* ---------- UTILS ---------- */
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

/* ---------- CENTRAL ---------- */
char	*join_free(char *res, char *buffer);
char	*read_cat(int fd, char *res);
char	*get_line(char *buffer);
char	*trim_buffer(char *buffer);
char	*get_next_line(int fd);

#endif
