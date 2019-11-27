/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:23:54 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:39:16 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *ptr, int value)
{
	char	*where;

	where = (char*)ptr;
	while (*where != '\0')
		where++;
	while (where != ptr)
	{
		if (*where == (char)value)
			return (where);
		where--;
	}
	if (*where == (char)value)
		return (where);
	return (NULL);
}
