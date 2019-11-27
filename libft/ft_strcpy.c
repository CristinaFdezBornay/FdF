/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:01:03 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:37:11 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*from;
	char	*to;

	from = (char*)src;
	to = dest;
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return (dest);
}
