#include "get_next_line.h"

char	*join_free(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*read_cat(int fd, char *res)
{
	char	*buffer;
	int		read_size;

	read_size = 1;
	if (!res)
		res = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = 0;
		res = join_free(res, buffer);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_line(char *buffer)
{
	char	*res;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		res[i] = '\n';
	return (res);
}

char	*trim_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	buffer = read_cat(fd, buffer);
	if (!buffer)
		return (NULL);
	res = get_line(buffer);
	buffer = trim_buffer(buffer);
	return (res);
}
