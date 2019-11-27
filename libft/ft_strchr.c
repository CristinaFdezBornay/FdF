/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:48:44 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:38:56 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *ptr, int value)
{
	char	*where;

	where = (char*)ptr;
	while (*where != '\0')
	{
		if (*where == (char)value)
			return (where);
		where++;
	}
	if (*where == (char)value)
		return (where);
	return (NULL);
}
