/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:20:55 by crfernan          #+#    #+#             */
/*   Updated: 2019/03/06 18:21:18 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_max_min(t_fdf **fdf, int i, int j)
{
	if ((*fdf)->max_z_input < (*fdf)->input[i][j].z)
		(*fdf)->max_z_input = (*fdf)->input[i][j].z;
	if ((*fdf)->min_z_input > (*fdf)->input[i][j].z)
		(*fdf)->min_z_input = (*fdf)->input[i][j].z;
}

size_t		find_min_max_z(t_fdf **fdf)
{
	int		i;
	int		j;

	(*fdf)->max_z_input = (*fdf)->input[0][0].z;
	(*fdf)->min_z_input = (*fdf)->input[0][0].z;
	i = -1;
	while (++i < MAX_Y)
	{
		j = -1;
		while (++j < MAX_X)
			set_max_min(fdf, i, j);
	}
	i = -1;
	while (++i < (*fdf)->input_y)
	{
		j = -1;
		while (++j < (*fdf)->input_x)
			(*fdf)->input[i][j].z -= (*fdf)->min_z_input;
	}
	(*fdf)->max_z_input -= (*fdf)->min_z_input;
	(*fdf)->min_z_input = 0;
	return (0);
}

void		save_input(t_fdf **fdf, int i, int j, char **somehow)
{
	(*fdf)->input[i][j].x = j - (*fdf)->input_x / 2;
	(*fdf)->input[i][j].y = i - (*fdf)->input_y / 2;
	(*fdf)->input[i][j].z = ft_atoi(somehow[0]);
	if (somehow[1] != NULL)
	{
		(*fdf)->input[i][j].color = ft_atoi_base(somehow[1], 16);
		if (i == 0 && j == 0)
		{
			(*fdf)->color_bottom = (*fdf)->input[i][j].color;
			(*fdf)->color_top = (*fdf)->input[i][j].color;
		}
		if ((*fdf)->color_bottom > (*fdf)->input[i][j].color)
			(*fdf)->color_bottom = (*fdf)->input[i][j].color;
		if ((*fdf)->color_top < (*fdf)->input[i][j].color)
			(*fdf)->color_top = (*fdf)->input[i][j].color;
	}
	else if (i == 0 && j == 0)
	{
		(*fdf)->color_top = 0xEEEEEE;
		(*fdf)->color_bottom = 0x333333;
		(*fdf)->input[i][j].color = 0x333333;
	}
	else
		(*fdf)->input[i][j].color = 0x333333;
}

size_t		reader(char *str, t_fdf **fdf)
{
	int			i;
	int			j;
	int			fd;
	char		**array_str;
	char		**somehow;

	i = -1;
	if (ft_input_alloc(fdf) == 1 || (fd = open(str, O_RDONLY)) <= 0)
		return (1);
	while (++i >= 0 && get_next_line(fd, &str) == 1)
	{
		j = -1;
		array_str = ft_strsplit(str, ' ');
		while (++j < (*fdf)->input_x)
		{
			somehow = ft_strsplit(array_str[j], ',');
			if (ft_strisnum(somehow[0]) == 0)
				return (1);
			save_input(fdf, i, j, somehow);
			free_array(&somehow);
		}
		free(str);
		free_array(&array_str);
	}
	return (find_min_max_z(fdf));
}
