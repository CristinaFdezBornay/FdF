/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:06:18 by ibaran            #+#    #+#             */
/*   Updated: 2019/02/07 17:08:21 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <libc.h>

char	*ft_strndup(const char *src, size_t n)
{
	char	*cpy;
	int		i;

	if (!(cpy = (char*)malloc(sizeof(char) * (ft_min(ft_strlen(src), n) + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && n != 0)
	{
		cpy[i] = src[i];
		i++;
		n--;
	}
	cpy[i] = '\0';
	return (cpy);
}
