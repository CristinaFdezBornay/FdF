/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:18:42 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/14 13:21:03 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

static int		ft_pow(int num, int pow)
{
	if (pow == 0)
		return (1);
	return (num * ft_pow(num, pow - 1));
}

static void		ft_stage2(long n, int len, int fd)
{
	char	to_print;

	while (len > 0)
	{
		to_print = (n / ft_pow(10, len - 1)) + 48;
		n %= ft_pow(10, len - 1);
		len--;
		write(fd, &to_print, 1);
	}
}

static int		ft_stage1(int n, int fd)
{
	int		len;
	long	num;
	long	number;

	number = n;
	len = 0;
	if (number == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	num = number;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	ft_stage2(number, len, fd);
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	ft_stage1(n, fd);
}
