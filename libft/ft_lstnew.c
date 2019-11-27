/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:38:01 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/14 18:02:35 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>
#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*fresh;

	if (!(fresh = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(fresh->content = (void*)ft_memalloc(content_size)))
		return (NULL);
	fresh->next = NULL;
	if (content == NULL)
	{
		fresh->content = (void*)NULL;
		fresh->content_size = 0;
	}
	else
	{
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	return (fresh);
}
