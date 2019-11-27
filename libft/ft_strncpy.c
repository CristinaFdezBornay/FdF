/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:08:17 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/26 15:34:35 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*from;
	char	*to;

	from = (char*)src;
	to = dest;
	while (n != 0 && *from)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	*to = '\0';
	while (n != 0)
	{
		*to = '\0';
		to++;
		n--;
	}
	return (dest);
}
