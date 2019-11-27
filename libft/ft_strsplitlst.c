/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:02:05 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/16 11:15:07 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>
#include "libft.h"

static int		ft_count(char *s, char c)
{
	char	*s_p;
	int		i;

	i = 0;
	s_p = (char*)s;
	while (*s_p != '\0')
	{
		while (*s_p == c && *s_p != '\0')
			s_p++;
		if (*s_p == '\0')
			break ;
		i++;
		while (*s_p != c && *s_p != '\0')
			s_p++;
	}
	return (i);
}

static t_list	*ft_allocate(char **begin, char c)
{
	int		i;
	t_list	*new;

	i = 0;
	while (**begin != c && **begin != '\0')
	{
		i++;
		*begin = *begin + 1;
	}
	new = ft_lstnew((const void*)(*begin - i), i);
	new->next = NULL;
	return (new);
}

t_list			*ft_strsplitlst(char const *s, char c)
{
	char		*s_p;
	t_list		*first;
	t_list		*list;
	t_list		*new;
	int			size;

	first = NULL;
	if (!s)
		return (NULL);
	size = ft_count((char*)s, c);
	s_p = (char*)s;
	while (size-- != 0)
	{
		while (*s_p == c && *s_p != '\0')
			s_p++;
		new = ft_allocate(&s_p, c);
		if (size + 1 == ft_count((char*)s, c))
			first = new;
		else
			list->next = new;
		list = new;
		while (*s_p != c && *s_p != '\0')
			s_p++;
	}
	return (first);
}
