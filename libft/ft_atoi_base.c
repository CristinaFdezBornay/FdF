/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:07:23 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 11:37:34 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi_base(const char *str, size_t base)
{
	int		to_return;
	int		sign;
	char	*pointer;

	pointer = (char*)str;
	sign = 1;
	to_return = 0;
	while (((*pointer >= 9 && *pointer <= 13) || *pointer == 32))
		pointer++;
	if (*pointer == '-')
	{
		sign = -1;
		pointer++;
	}
	else if ((*pointer == '0' && *(pointer + 1) == 'x') || *pointer == '+')
		pointer += (*pointer == '0' ? 2 : 1);
	while ((*pointer >= '0' && *pointer <= '9') || ft_isalpha(*pointer) == 1)
	{
		if (*pointer >= '0' && *pointer <= '9')
			to_return = (to_return * base) + (*pointer - 48);
		else
			to_return = (to_return * base) + (ft_toupper(*pointer) - 55);
		pointer++;
	}
	return (to_return * sign);
}
