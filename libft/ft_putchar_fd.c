/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:54:28 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/09 18:54:59 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}