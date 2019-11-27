/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:01:35 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 11:42:19 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		save_remainder_into_list(t_gnl **list, int fd, char *buffer, int i)
{
	t_gnl		*current;
	t_gnl		*new;

	current = *list;
	while (current && current->next && current->fd != fd)
		current = current->next;
	if (current && current->fd == fd && buffer[i + 1] != '\0')
		current->str = ft_strdup(buffer + i + 1);
	else if (buffer[i + 1] != '\0')
	{
		if (!(new = (t_gnl*)malloc(sizeof(*new))))
			return (-1);
		new->str = ft_strdup(buffer + i + 1);
		new->fd = fd;
		new->next = NULL;
		if (!(*list))
			*list = new;
		else
			current->next = new;
	}
	free(buffer);
	return (1);
}

int		line_memory_allocation(char **line, int new_size)
{
	char			*tmp;
	size_t			to_return;

	to_return = 0;
	if (!(*line))
	{
		if (!(*line = ft_strnew(new_size)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strdup(*line)))
			return (-1);
		free(*line);
		to_return = ft_strlen(tmp);
		if (!(*line = ft_strnew(new_size + to_return)))
			return (-1);
		ft_strcpy(*line, tmp);
		free(tmp);
	}
	return ((int)to_return);
}

int		put_buffer_into_line(char *buffer, char **line, t_gnl **list,
		int fd)
{
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != EOF && buffer[i] != '\0')
		i++;
	if ((j = line_memory_allocation(line, i)) == -1)
		return (-1);
	ft_strncpy((*line) + j, buffer, i);
	if (buffer[i] == '\n')
		return (save_remainder_into_list(list, fd, buffer, i));
	else if (buffer[i] == '\0')
		return (read_from_fd(buffer, line, list, fd));
	free(buffer);
	return (1);
}

int		read_from_fd(char *buffer, char **line, t_gnl **list, int fd)
{
	int		check_read;

	if (buffer)
		free(buffer);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	check_read = read(fd, buffer, BUFF_SIZE);
	if (check_read <= 0)
	{
		free(buffer);
		if (check_read < 0)
			return (-1);
		if (check_read == 0 && *line != NULL && ft_strlen(*line) != 0)
			return (1);
		return (0);
	}
	buffer[check_read] = '\0';
	return (put_buffer_into_line(buffer, line, list, fd));
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*prev_or_curr[2];
	char			*buffer;

	if (fd < 0 || !(line))
		return (-1);
	*line = NULL;
	prev_or_curr[1] = list;
	prev_or_curr[0] = prev_or_curr[1];
	while (prev_or_curr[1] != NULL && prev_or_curr[1]->fd != fd)
	{
		prev_or_curr[0] = prev_or_curr[1];
		prev_or_curr[1] = prev_or_curr[1]->next;
	}
	if (prev_or_curr[1] != NULL)
	{
		if (prev_or_curr[0] == prev_or_curr[1])
			list = list->next;
		buffer = ft_strdup(prev_or_curr[1]->str);
		prev_or_curr[0]->next = prev_or_curr[1]->next;
		free(prev_or_curr[1]->str);
		free(prev_or_curr[1]);
		return (put_buffer_into_line(buffer, line, &list, fd));
	}
	return (read_from_fd(buffer = NULL, line, &list, fd));
}
