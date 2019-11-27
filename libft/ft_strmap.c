/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:49:41 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/15 14:50:32 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_pointer;
	char	*fresh;
	char	*f_pointer;

	if (s)
	{
		if (!(fresh = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		f_pointer = fresh;
		s_pointer = (char*)s;
		while (*s_pointer)
		{
			*f_pointer = f(*s_pointer);
			s_pointer++;
			f_pointer++;
		}
		*f_pointer = '\0';
		return (fresh);
	}
	else
		return (NULL);
}
