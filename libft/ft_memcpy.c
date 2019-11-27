/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:19:51 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:35:48 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_what;
	unsigned char	*s_what;

	d_what = (unsigned char*)dest;
	s_what = (unsigned char*)src;
	while (n != 0)
	{
		*d_what = *s_what;
		d_what++;
		s_what++;
		n--;
	}
	return (dest);
}
