/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:45 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/28 12:59:34 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;

	if (!(result = (char*)malloc(sizeof(char) *
		(ft_strlen(s2) + ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(result, s1);
	i = 0;
	while (result[i])
		i++;
	ft_strcpy(result + i, s2);
	return (result);
}
