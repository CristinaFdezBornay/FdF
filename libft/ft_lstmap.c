/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:09:21 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/14 17:31:16 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>
#include "libft.h"

static t_list	*ft_stage2(t_list **lst, t_list *(*f)(t_list *elem))
{
	t_list		*current_in;
	t_list		*current_out;
	t_list		*new;
	t_list		*first;

	current_in = *lst;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(current_in);
	first = new;
	current_out = new;
	current_in = current_in->next;
	while (current_in != NULL)
	{
		free(new);
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		new = f(current_in);
		current_out->next = new;
		current_out = new;
		current_in = current_in->next;
	}
	return (first);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (lst)
		return (ft_stage2(&lst, f));
	else
		return (NULL);
}
