/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:00 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/15 10:56:04 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

static int		ft_count(char const *s)
{
	char	*s_p;
	int		i;

	i = 0;
	s_p = (char*)s;
	while ((*s_p == ' ' || *s_p == '\t' || *s_p == '\n') && *s_p != '\0')
		s_p++;
	while (*s_p != '\0')
	{
		i++;
		s_p++;
	}
	if (s_p != (char*)s)
		s_p--;
	while ((*s_p == ' ' || *s_p == '\t' || *s_p == '\n') && s_p != (char*)s)
	{
		s_p--;
		i--;
	}
	return (i);
}

static char		*ft_zerrr(void)
{
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char))))
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *s)
{
	char	*s_p;
	char	*d_p;
	char	*dest;
	int		len;

	if (!s)
		return (NULL);
	s_p = (char*)s;
	while ((*s_p == ' ' || *s_p == '\t' || *s_p == '\n') && *s_p != '\0')
		s_p++;
	if (*s_p == '\0')
		return (ft_zerrr());
	len = ft_count(s);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	d_p = dest;
	while (len != 0)
	{
		*d_p = *s_p;
		d_p++;
		s_p++;
		len--;
	}
	*d_p = '\0';
	return (dest);
}
