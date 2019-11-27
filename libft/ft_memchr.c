/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:23:54 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:35:29 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*where;

	where = (unsigned char*)ptr;
	while (n != 0)
	{
		if (*where == (unsigned char)value)
			return (where);
		where++;
		n--;
	}
	return (NULL);
}
