/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:03:10 by ibaran            #+#    #+#             */
/*   Updated: 2019/02/06 14:06:10 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char	*ft_nctoa(char c, size_t n)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = c;
		i++;
	}
	result[n] = '\0';
	return (result);
}
