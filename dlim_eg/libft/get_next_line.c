/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:45:38 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 12:46:07 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_line(char *stack)
{
	int	i;

	i = 0;
	while (stack && stack[i] != '\0')
	{
		if (stack[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

static char	*get_line(char **stack)
{
	int		i;
	char	*old_stack;
	char	*ret;
	int		old_stack_len;

	i = check_line(*stack);
	if (i == -1 && ft_strlen(*stack) == 0)
		return (NULL);
	else
	{
		old_stack = *stack;
		old_stack_len = ft_strlen(old_stack);
		ret = ft_substr(old_stack, 0, i);
		*stack = ft_substr(old_stack, i, old_stack_len);
		free (old_stack);
		old_stack = NULL;
	}
	return (ret);
}

static int	read_file(int fd, char **stack, char *heap)
{
	char	*temp_stack;
	int		ret;

	while (1)
	{
		ret = read(fd, heap, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (ret);
		heap[ret] = '\0';
		if (*stack)
		{
			temp_stack = *stack;
			*stack = ft_strjoin(temp_stack, heap);
			free(temp_stack);
			temp_stack = NULL;
		}
		else
			*stack = ft_substr(heap, 0, ft_strlen(heap));
		if (ret < BUFFER_SIZE)
			return (0);
		if (check_line(*stack) != -1)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*heap;
	static char	*stack[OPEN_MAX];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	heap = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!heap || read_file(fd, &stack[fd], heap) == -1)
	{
		free (stack[fd]);
		stack[fd] = NULL;
		ret = NULL;
	}
	else
	{
		ret = get_line(&stack[fd]);
		if (ft_strlen(stack[fd]) == 0 || !ret)
		{
			free(stack[fd]);
			stack[fd] = NULL;
		}
	}
	free(heap);
	heap = NULL;
	return (ret);
}
