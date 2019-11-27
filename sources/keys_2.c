/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:07:07 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 18:06:05 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_zoom(int key, t_fdf **fdf)
{
	if (key == 27)
	{
		(*fdf)->image_x_input *= (*fdf)->zoom;
		(*fdf)->image_y_input *= (*fdf)->zoom;
	}
	else
	{
		(*fdf)->image_x_input /= (*fdf)->zoom;
		(*fdf)->image_y_input /= (*fdf)->zoom;
	}
	re_project(fdf, (*fdf)->proj);
}

void		key_angle(int key, t_fdf **fdf)
{
	if (key == 12 && (*fdf)->angle + 0.05 < 0.523599)
		(*fdf)->angle += 0.05;
	else if (key == 14 && (*fdf)->angle - 0.05 > 0.123599)
		(*fdf)->angle -= 0.05;
	re_project(fdf, (*fdf)->proj);
}

void		find_middle_color(t_fdf **fdf)
{
	unsigned int	color_to_set;
	float			z_rat;
	int				i;
	int				j;

	i = 0;
	while (i < (*fdf)->input_y)
	{
		j = 0;
		while (j < (*fdf)->input_x)
		{
			z_rat = (Z_INP) / ((*fdf)->max_z_input - (*fdf)->min_z_input);
			z_rat = ((*fdf)->max_z == (*fdf)->min_z ? 0 : z_rat);
			color_to_set =
				lround(((float)R_OF_COL(COLOR_BUT) * (1.0 - z_rat) +
					((float)R_OF_COL(COLOR_TOP) * z_rat))) * 0x10000 +
				lround(((float)G_OF_COL(COLOR_BUT) * (1.0 - z_rat) +
					((float)G_OF_COL(COLOR_TOP) * z_rat))) * 0x100 +
				lround(((float)B_OF_COL(COLOR_BUT) * (1.0 - z_rat) +
					((float)B_OF_COL(COLOR_TOP) * z_rat)));
			(*fdf)->input[i][j].color = color_to_set;
			j++;
		}
		i++;
	}
}

void		key_color(int key, t_fdf **fdf)
{
	key = 0;
	if ((*fdf)->color_top == 0xDDFFDD)
	{
		(*fdf)->color_top = 0xDDDDFF;
		(*fdf)->color_bottom = 0x000099;
	}
	else if ((*fdf)->color_top == 0xFFDDDD)
	{
		(*fdf)->color_top = 0xDDFFDD;
		(*fdf)->color_bottom = 0x009900;
	}
	else if ((*fdf)->color_top == 0xEEEEEE)
	{
		(*fdf)->color_top = 0xFFDDDD;
		(*fdf)->color_bottom = 0x990000;
	}
	else if ((*fdf)->color_top == 0xDDDDFF)
	{
		(*fdf)->color_top = 0xEEEEEE;
		(*fdf)->color_bottom = 0x333333;
	}
	find_middle_color(fdf);
	re_project(fdf, (*fdf)->proj);
}

int			keyboard(int key, t_fdf **fdf)
{
	if (key == 53)
		key_esc(key, fdf);
	if ((key >= 0 && key <= 2) || key == 13 || key == 6 || key == 8)
		key_rotation(key, fdf);
	if (key >= 123 && key <= 126)
		key_trans(key, fdf);
	if (key == 69 || key == 78)
		key_altitude(key, fdf);
	if (key == 49)
		key_color(key, fdf);
	if (key == 27 || key == 24)
		key_zoom(key, fdf);
	if (key == 12 || key == 14)
		key_angle(key, fdf);
	if (key == 48)
		key_change_projection(key, fdf);
	return (0);
}
