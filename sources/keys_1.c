/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:07:02 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 16:34:13 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_esc(int key, t_fdf **fdf)
{
	key = 0;
	mlx_destroy_image((*fdf)->mlx, (*fdf)->image);
	mlx_clear_window((*fdf)->mlx, (*fdf)->window);
	mlx_destroy_window((*fdf)->mlx, (*fdf)->window);
	free_all(fdf);
	exit(0);
}

void		key_rotation(int key, t_fdf **fdf)
{
	if (key == 0 && Z_DEG + DEGREE_STEP < 2.15)
		Z_DEG += DEGREE_STEP;
	if (key == 2 && Z_DEG - DEGREE_STEP > -0.7)
		Z_DEG -= DEGREE_STEP;
	if (key == 13 && X_DEG + DEGREE_STEP < 2.15)
		X_DEG += DEGREE_STEP;
	if (key == 1 && X_DEG - DEGREE_STEP > -0.7)
		X_DEG -= DEGREE_STEP;
	if (key == 6 && Y_DEG + DEGREE_STEP < 2.15)
		Y_DEG += DEGREE_STEP;
	if (key == 8 && Y_DEG - DEGREE_STEP > -0.7)
		Y_DEG -= DEGREE_STEP;
	re_project(fdf, (*fdf)->proj);
}

void		key_trans(int key, t_fdf **fdf)
{
	if (key == 123)
		(*fdf)->trans_x += MOVE_STEP;
	if (key == 124)
		(*fdf)->trans_x -= MOVE_STEP;
	if (key == 125)
		(*fdf)->trans_y -= MOVE_STEP;
	if (key == 126)
		(*fdf)->trans_y += MOVE_STEP;
	re_project(fdf, (*fdf)->proj);
}

void		key_altitude(int key, t_fdf **fdf)
{
	if (key == 69)
		(*fdf)->altitude_coef += 0.2;
	else
		(*fdf)->altitude_coef -= 0.2;
	(*fdf)->max_z = (*fdf)->max_z_input * (*fdf)->altitude_coef;
	(*fdf)->min_z = (*fdf)->min_z_input * (*fdf)->altitude_coef;
	re_project(fdf, (*fdf)->proj);
}

void		key_change_projection(int key, t_fdf **fdf)
{
	key = 0;
	if ((*fdf)->proj == 0)
	{
		(*fdf)->proj = 1;
		re_project(fdf, 1);
	}
	else
	{
		(*fdf)->proj = 0;
		re_project(fdf, 0);
	}
}
