/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:00:19 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/30 16:35:53 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	char			*search_for;
	char			*search_in;
	char			*remember;

	search_in = (char*)str1;
	search_for = (char*)str2;
	if (*search_in == '\0' && *search_for != '\0')
		return (NULL);
	while (*search_in != '\0')
	{
		remember = search_in;
		while (*search_for != '\0' && *search_in != '\0'
		&& *search_for == *search_in)
		{
			if (*(search_for + 1) == '\0')
				return (remember);
			search_for++;
			search_in++;
		}
		search_for = (char*)str2;
		search_in = remember + 1;
	}
	if ((char)*str2 == '\0')
		return ((char*)str1);
	return (NULL);
}
