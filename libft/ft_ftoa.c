/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:49:54 by ibaran            #+#    #+#             */
/*   Updated: 2019/02/07 21:35:51 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

static int				ft_exp_ent(unsigned long long nbr)
{
	if (nbr != 0)
		return (ft_exp_ent(nbr / 10) + 1);
	return (0);
}

static long double		ft_round(long double nbr, int precision)
{
	int				rem_precision;
	long double		rem_nbr;

	rem_nbr = 10 * (nbr - (int)nbr);
	rem_precision = precision++;
	while (--precision != 0)
		rem_nbr = 10 * (rem_nbr - (int)rem_nbr);
	if (rem_nbr > 5)
		nbr += 1.0 / ft_power(10, rem_precision + 1);
	return (nbr);
}

static char				*fill_string(char *out, int exp_entire,
						unsigned long long entire_p)
{
	while (entire_p > 0)
	{
		out[exp_entire - 1] = '0' + (entire_p % 10);
		entire_p /= 10;
		exp_entire--;
	}
	return (out);
}

char					*ft_ftoa(long double nbr, int precision)
{
	unsigned long long	entire_p;
	long double			decimal_p;
	int					exp_entire;
	char				*out;
	int					i;

	nbr = ft_round(nbr, precision);
	exp_entire = ft_exp_ent((unsigned long long)nbr);
	if (exp_entire == 0)
		exp_entire = 1;
	if (!(out = (char*)malloc(sizeof(char) * (exp_entire + precision + 2))))
		return (NULL);
	out[exp_entire + precision + 1] = '\0';
	out[0] = '0';
	entire_p = (unsigned long long)(nbr);
	decimal_p = nbr - entire_p;
	i = 0;
	while (i < precision)
	{
		out[exp_entire + i + 1] = '0' + (int)(decimal_p * 10);
		decimal_p = decimal_p * 10 - (int)(decimal_p * 10);
		i++;
	}
	out[exp_entire] = '.';
	return (out = fill_string(out, exp_entire, entire_p));
}
