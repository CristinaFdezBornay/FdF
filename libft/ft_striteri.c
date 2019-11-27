/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:12 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/15 10:53:03 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*pointer;

	if (s && f)
	{
		pointer = s;
		while (*pointer != '\0')
		{
			f(pointer - s, pointer);
			pointer++;
		}
	}
}
