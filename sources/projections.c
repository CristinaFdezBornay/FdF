/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:13:44 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 15:02:37 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	find_middle_y(t_fdf **fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < MAX_Y)
	{
		j = -1;
		while (++j < MAX_X)
		{
			if (i == 0 && j == 0)
			{
				(*fdf)->max_y = ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT);
				(*fdf)->min_y = ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT);
			}
			else
			{
				if ((*fdf)->max_y < ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT))
					(*fdf)->max_y = ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT);
				if ((*fdf)->min_y > ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT))
					(*fdf)->min_y = ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT);
			}
		}
	}
	return (0);
}

size_t	put_message(t_fdf **fdf)
{
	mlx_string_put(POINTERS, 20, 15, 0xFFFFFF, "KEYBOARD CONTROL:");
	mlx_string_put(POINTERS, 20, 35, 0xFFFFFF, " -> Rotation:");
	mlx_string_put(POINTERS, 20, 55, 0xFFFFFF, "     A / D - Z-rotation");
	mlx_string_put(POINTERS, 20, 75, 0xFFFFFF, "     W / S - X-rotation");
	mlx_string_put(POINTERS, 20, 95, 0xFFFFFF, "     Z / C - Y-rotation");
	mlx_string_put(POINTERS, 20, 115, 0xFFFFFF, " -> Zoom: Up + and -");
	mlx_string_put(POINTERS, 20, 135, 0xFFFFFF, " -> Altitude: Right + and -");
	mlx_string_put(POINTERS, 20, 155, 0xFFFFFF, " -> Camera: Q / E");
	mlx_string_put(POINTERS, 20, 175, 0xFFFFFF, " -> Color: Space");
	mlx_string_put(POINTERS, 20, 195, 0xFFFFFF, " -> Projection: Tab");
	mlx_string_put(POINTERS, 20, 215, 0xFFFFFF, " -> Exit: Esc");
	mlx_string_put(POINTERS, 990, 950, 0xFFFFFF, "Authors: Ivan Baran and ");
	mlx_string_put(POINTERS, 1230, 950, 0xFFFFFF, "Cristina Fernandez Bornay");
	return (0);
}

size_t	re_project(t_fdf **fdf, int proj)
{
	rotation(fdf);
	find_middle_y(fdf);
	if (proj == 0)
		fill_isometric_projection(fdf);
	else
		fill_parallel_projection(fdf);
	bohemian_algorithm(fdf);
	fill_image(&(*fdf)->image_string, (*fdf)->image_grid);
	mlx_put_image_to_window((*fdf)->mlx, (*fdf)->window, (*fdf)->image, 0, 0);
	put_message(fdf);
	return (0);
}

size_t	fill_parallel_projection(t_fdf **fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (*fdf)->input_y)
	{
		j = -1;
		while (++j < (*fdf)->input_x)
		{
			(*fdf)->projection[i][j].x = (*fdf)->input[i][j].x *
				(*fdf)->image_x_input + (*fdf)->trans_x;
			(*fdf)->projection[i][j].y = (*fdf)->input[i][j].y *
				(*fdf)->image_y_input + (*fdf)->trans_y;
			(*fdf)->projection[i][j].z = (*fdf)->input[i][j].z;
			(*fdf)->projection[i][j].color = (*fdf)->matrix[i][j].color;
		}
	}
	return (0);
}

size_t	fill_isometric_projection(t_fdf **fdf)
{
	int				i;
	int				j;

	i = -1;
	while (++i < (*fdf)->input_y)
	{
		j = -1;
		while (++j < (*fdf)->input_x)
		{
			X_PRO = ((X_MAT + Y_MAT) * cos(VIEW_DEG)) + X_TRANS;
			Y_PRO = ((Y_MAT - X_MAT) * sin(VIEW_DEG) - Z_MAT) -
				(*fdf)->min_y + (Y_TRANS - ((*fdf)->max_y - (*fdf)->min_y) / 2);
			Z_PRO = 0;
			(*fdf)->projection[i][j].color = (*fdf)->matrix[i][j].color;
		}
	}
	return (0);
}
