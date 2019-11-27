/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:01:40 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/15 14:51:32 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_pointer;
	char			*fresh;
	char			*f_pointer;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(fresh = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		f_pointer = fresh;
		s_pointer = (char*)s;
		while (*s_pointer != '\0')
		{
			*f_pointer = f(i, *s_pointer);
			s_pointer++;
			f_pointer++;
			i++;
		}
		*f_pointer = '\0';
		return (fresh);
	}
	else
		return (NULL);
}
