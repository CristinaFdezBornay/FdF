/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:21:59 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:37:37 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *dest, const char *src)
{
	char	*to;
	char	*from;

	to = dest;
	from = (char*)src;
	while (*to != '\0')
		to++;
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return (dest);
}
