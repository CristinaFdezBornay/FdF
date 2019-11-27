/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:19:46 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:39:33 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *ptr1, const char *ptr2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)ptr1;
	str2 = (unsigned char*)ptr2;
	if (n == 0)
		return ((unsigned char)0);
	while (*str1 != '\0' && *str2 != '\0' && n != 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		if (n != 0)
		{
			str1++;
			str2++;
		}
	}
	return (*str1 - *str2);
}
