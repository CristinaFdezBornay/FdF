/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:32:07 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/31 19:33:08 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*to;
	char		*from;
	size_t		i;
	int			k;
	int			maxim;

	k = 0;
	i = 0;
	to = dest;
	from = (char*)src;
	i = ft_strlen(dest);
	while (*to != '\0')
		to++;
	maxim = size - i - 1;
	while (*from != '\0' && k++ < maxim)
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return (ft_strlen((char*)src) + ft_min(i, size));
}
