/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:54:43 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:35:22 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d_what;
	unsigned char	*s_what;

	d_what = (unsigned char*)dest;
	s_what = (unsigned char*)src;
	while (n != 0)
	{
		*d_what = *s_what;
		if (*s_what == (unsigned char)c)
			return (++d_what);
		d_what++;
		s_what++;
		n--;
	}
	return ((unsigned char*)NULL);
}
