/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:32:07 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:38:28 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char		*to;
	char		*from;

	to = dest;
	from = (char*)src;
	while (*to != '\0')
		to++;
	while (*from != '\0' && n != 0)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	*to = '\0';
	return (dest);
}
