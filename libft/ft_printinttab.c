/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:13:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/02/27 12:07:19 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printinttab(int **array, size_t size)
{
	size_t		i;

	while (*array != NULL)
	{
		i = 0;
		while (i < size)
		{
			ft_putnbr((*array)[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		array++;
	}
}
