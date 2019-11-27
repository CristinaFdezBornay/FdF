/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:36:42 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 10:52:45 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

static int		ft_check(char **search_for, char **search_in, int *i)
{
	if (*search_for && *search_in)
	{
		*search_for = *search_for + 1;
		if (**search_for == '\0')
			return (1);
		*search_in = *search_in + 1;
		*i = *i + 1;
		return (0);
	}
	return (1);
}

char			*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	char		*search_for;
	char		*search_in;
	char		*remember;
	int			i;

	search_in = (char*)str1;
	search_for = (char*)str2;
	if (len == 0)
		return (NULL);
	if (*search_in == '\0' && *search_for != '\0')
		return (NULL);
	if (*search_for == '\0')
		return ((char*)str1);
	while (*search_in != '\0' && len-- != 0)
	{
		i = 0;
		remember = search_in;
		while (*search_for && *search_in
				&& *search_for == *search_in && (int)len - i >= 0)
			if ((ft_check(&search_for, &search_in, &i) == 1))
				return (remember);
		search_for = (char*)str2;
		search_in = remember + 1;
	}
	return (NULL);
}
