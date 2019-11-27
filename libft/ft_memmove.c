/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:33:58 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/30 17:58:35 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d_what;
	char		*s_what;

	d_what = (char*)dest;
	s_what = (char*)src;
	if (s_what > d_what)
	{
		while (n != 0)
		{
			*d_what = *s_what;
			d_what++;
			s_what++;
			n--;
		}
	}
	else
		while (n != 0)
		{
			*(d_what + n - 1) = *(s_what + n - 1);
			n--;
		}
	return (dest);
}
