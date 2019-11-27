/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:01:02 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 16:12:04 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>

static int		ft_count(char *s, char c)
{
	char	*s_p;
	int		i;

	i = 0;
	s_p = (char*)s;
	while (*s_p != '\0')
	{
		while (*s_p == c && *s_p != '\0')
			s_p++;
		if (*s_p == '\0')
			break ;
		i++;
		while (*s_p != c && *s_p != '\0')
			s_p++;
	}
	return (i);
}

static char		*ft_allocate(char **begin, char c)
{
	int		i;
	char	*string;

	i = 0;
	while (**begin != c && **begin != '\0')
	{
		i++;
		*begin = *begin + 1;
	}
	if (!(string = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	*begin -= i;
	i = 0;
	while (**begin != c && **begin != '\0')
	{
		string[i] = **begin;
		*begin = *begin + 1;
		i++;
	}
	string[i] = '\0';
	return (string);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*s_p;
	char	**array;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_count((char*)s, c);
	if (!(array = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	array[size] = NULL;
	s_p = (char*)s;
	while (i < size)
	{
		while (*s_p == c)
			s_p++;
		array[i] = ft_allocate(&s_p, c);
		while (*s_p != c && *s_p != '\0')
			s_p++;
		i++;
	}
	return (array);
}
