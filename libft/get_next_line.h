/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:16:18 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 11:43:30 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

# include <string.h>
# include <libc.h>
# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int					read_from_fd(char *buffer, char **line,
					t_gnl **list, int fd);
int					put_buffer_into_line(char *buffer, char **line,
					t_gnl **list, int fd);
int					line_memory_allocation(char **line, int new_size);
int					save_remainder_into_list(t_gnl **list, int fd,
					char *buffer, int i);

#endif
