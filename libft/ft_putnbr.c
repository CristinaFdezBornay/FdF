/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:49:34 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/14 13:16:31 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static int		ft_pow(int num, int pow)
{
	if (pow == 0)
		return (1);
	return (num * ft_pow(num, pow - 1));
}

static void		ft_stage2(long n, int len)
{
	char	to_print;

	while (len > 0)
	{
		to_print = (n / ft_pow(10, len - 1)) + 48;
		n %= ft_pow(10, len - 1);
		len--;
		write(1, &to_print, 1);
	}
}

static int		ft_stage1(int n)
{
	int		len;
	long	num;
	long	number;

	number = n;
	len = 0;
	if (number == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	num = number;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	ft_stage2(number, len);
	return (0);
}

void			ft_putnbr(int n)
{
	ft_stage1(n);
}
