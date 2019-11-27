/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:47:57 by crfernan          #+#    #+#             */
/*   Updated: 2019/01/31 14:49:22 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

static int	ft_exp(long long nbr)
{
	if (nbr != 0)
		return (ft_exp(nbr / 10) + 1);
	return (0);
}

char		*ft_itoa(long long nbr)
{
	int		exp;
	char	*out;

	out = NULL;
	exp = ft_exp(nbr);
	if (nbr < 0)
		exp++;
	if (nbr == 0)
		exp = 1;
	if (!(out = (char*)malloc(sizeof(char) * (exp + 1))))
		return (NULL);
	out[exp] = '\0';
	out[0] = '0';
	if (nbr < 0)
		out[0] = '-';
	while (nbr != 0)
	{
		if (nbr < 0)
			out[exp - 1] = (-(nbr % 10)) + '0';
		else
			out[exp - 1] = (nbr % 10) + '0';
		nbr /= 10;
		exp--;
	}
	return (out);
}
