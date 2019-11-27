/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:35:55 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/09 11:41:31 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*pointer;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	pointer = str;
	while (size != 0)
	{
		*pointer = '\0';
		pointer++;
		size--;
	}
	*pointer = '\0';
	return (str);
}
