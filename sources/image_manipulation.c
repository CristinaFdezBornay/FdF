/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:01:17 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 16:34:17 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_image(char **image_string, unsigned int **grid)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < IMAGE_Y)
	{
		j = 0;
		while (j < IMAGE_X)
		{
			(*image_string)[k + 0] = (char)(grid[i][j] % 256 % 256);
			(*image_string)[k + 1] = (char)(grid[i][j] / 256 % 256);
			(*image_string)[k + 2] = (char)(grid[i][j] / 256 / 256);
			(*image_string)[k + 3] = 0;
			k += 4;
			j++;
		}
		i++;
	}
}

size_t	function(t_matrix point_zero, t_matrix point_one, t_fdf **fdf)
{
	int					decision;
	int					y;
	int					x;
	int					yi;

	yi = 1;
	if (DY < 0)
		yi *= -1;
	decision = 2 * yi * DY - DX;
	y = point_zero.y;
	x = point_zero.x;
	while (x <= point_one.x)
	{
		if (x >= 0 && y >= 0 && x < IMAGE_X && y < IMAGE_Y)
			(*fdf)->image_grid[y][x] =
				MID_COLOR(point_one.color, point_zero.color);
		if (decision > 0)
		{
			y += yi;
			decision -= 2 * DX;
		}
		decision += 2 * DY * yi;
		x++;
	}
	return (0);
}

size_t	another_function(t_matrix point_zero, t_matrix point_one, t_fdf **fdf)
{
	int		decision;
	int		y;
	int		x;
	int		xi;

	xi = 1;
	if (DX < 0)
		xi *= -1;
	decision = 2 * DX * xi - DY;
	x = point_zero.x;
	y = point_zero.y;
	while (y <= point_one.y)
	{
		if (x >= 0 && y >= 0 && x < IMAGE_X && y < IMAGE_Y)
			(*fdf)->image_grid[y][x] =
				MID_COLOR(point_one.color, point_zero.color);
		if (decision > 0)
		{
			x += xi;
			decision -= 2 * DY;
		}
		decision += 2 * DX * xi;
		y++;
	}
	return (0);
}

size_t	draw_line(t_matrix point_zero, t_matrix point_one, t_fdf **fdf)
{
	if (fabsf(point_one.y - point_zero.y) < fabsf(point_one.x - point_zero.x))
	{
		if (point_zero.x > point_one.x)
			function(point_one, point_zero, fdf);
		else
			function(point_zero, point_one, fdf);
	}
	else
	{
		if (point_zero.y > point_one.y)
			another_function(point_one, point_zero, fdf);
		else
			another_function(point_zero, point_one, fdf);
	}
	return (0);
}

size_t	bohemian_algorithm(t_fdf **fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < IMAGE_Y)
	{
		j = -1;
		while (++j < IMAGE_X)
			(*fdf)->image_grid[i][j] = 0x000000;
	}
	i = -1;
	while (++i < (*fdf)->input_y)
	{
		j = -1;
		while (++j < (*fdf)->input_x)
		{
			if (j != (*fdf)->input_x - 1)
				draw_line(PROJECTION[i][j], PROJECTION[i][j + 1], fdf);
			if (i != (*fdf)->input_y - 1)
				draw_line(PROJECTION[i][j], PROJECTION[i + 1][j], fdf);
		}
	}
	return (0);
}
