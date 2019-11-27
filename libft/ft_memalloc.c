/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:26:32 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/15 12:54:16 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*memory;
	size_t			i;
	unsigned char	*m_pointer;

	i = 0;
	if (!(memory = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	m_pointer = memory;
	while (i < size)
	{
		*m_pointer = '\0';
		m_pointer++;
		i++;
	}
	return (memory);
}
