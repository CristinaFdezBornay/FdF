/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:36:28 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/31 19:46:28 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_sumstrstr(const char *str1, const char *str2)
{
	char			*search_for;
	char			*search_in;
	char			*remember;
	size_t			result;

	result = 0;
	search_in = (char*)str1;
	search_for = (char*)str2;
	if (*search_in == '\0' && *search_for != '\0')
		return (0);
	while (*search_in != '\0')
	{
		remember = search_in;
		while (*search_for != '\0' && *search_in != '\0'
		&& *search_for == *search_in)
		{
			if (*(search_for + 1) == '\0')
				result++;
			search_for++;
			search_in++;
		}
		search_for = (char*)str2;
		search_in = remember + 1;
	}
	return ((char)*str2 == '\0' ? 0 : result);
}
