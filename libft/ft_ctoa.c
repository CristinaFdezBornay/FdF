/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:27:45 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/28 14:30:06 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char	*ft_ctoa(char c)
{
	char	*result;

	if (!(result = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
