/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:15:55 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/15 12:55:38 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	char			*f_pointer;
	char			*s_pointer;

	if (s)
	{
		if (!(fresh = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		f_pointer = fresh;
		s_pointer = (char*)&s[start];
		while (len != 0 && *s_pointer)
		{
			*f_pointer = *s_pointer;
			f_pointer++;
			s_pointer++;
			len--;
		}
		*f_pointer = '\0';
		return (fresh);
	}
	else
		return (NULL);
}
