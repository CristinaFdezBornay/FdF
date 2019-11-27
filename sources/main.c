/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:50:37 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 18:03:28 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_color_matrix(t_fdf **fdf)
{
	int				i;
	int				j;
	float			z_rat;
	unsigned int	color_to_set;

	i = 0;
	while (i < (*fdf)->input_y)
	{
		j = 0;
		while (j < (*fdf)->input_x)
		{
			z_rat = (Z_MAT - (*fdf)->min_z) / ((*fdf)->max_z - (*fdf)->min_z);
			z_rat = ((*fdf)->max_z == (*fdf)->min_z ? 0 : z_rat);
			color_to_set =
				lround(((float)R_OF_COL(COLOR_BUT) * (1.0 - z_rat) +
					((float)R_OF_COL(COLOR_TOP) * z_rat))) * 0x10000 +
				lround(((float)G_OF_COL(COLOR_BUT) * (1.0 - z_rat) +
					((float)G_OF_COL(COLOR_TOP) * z_rat))) * 0x100 +
				lround(((float)B_OF_COL(COLOR_BUT) * (1.0 - z_rat) +
					((float)B_OF_COL(COLOR_TOP) * z_rat)));
			(*fdf)->matrix[i][j].color = color_to_set;
			j++;
		}
		i++;
	}
}

void		math_of_rotation(t_fdf **fdf, int i, int j)
{
	X_MAT = X_ZOOM * (X_INP * cos(Y_DEG) * cos(Z_DEG) +
		Y_INP * (sin(X_DEG) * sin(Y_DEG) * cos(Z_DEG) -
		cos(X_DEG) * sin(Z_DEG)) +
		Z_INP * (cos(X_DEG) * sin(Y_DEG) * cos(Z_DEG) +
		sin(X_DEG) * sin(Z_DEG)));
	Y_MAT = Y_ZOOM * (X_INP * cos(Y_DEG) * sin(Z_DEG) +
		Y_INP * (sin(X_DEG) * sin(Y_DEG) * sin(Z_DEG) +
		cos(X_DEG) * cos(Z_DEG)) +
		Z_INP * (cos(X_DEG) * sin(Y_DEG) * sin(Z_DEG) -
		sin(X_DEG) * cos(Z_DEG)));
	Z_MAT = Y_ZOOM * (X_INP * -sin(Y_DEG) +
		Y_INP * sin(X_DEG) * cos(Y_DEG) +
		Z_INP * cos(X_DEG) * cos(Y_DEG));
	if (i == 0 && j == 0)
	{
		(*fdf)->max_z = Z_MAT;
		(*fdf)->min_z = Z_MAT;
	}
	else
	{
		if ((*fdf)->max_z < Z_MAT)
			(*fdf)->max_z = Z_MAT;
		if ((*fdf)->min_z > Z_MAT)
			(*fdf)->min_z = Z_MAT;
	}
}

size_t		rotation(t_fdf **fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*fdf)->input_y)
	{
		j = 0;
		while (j < (*fdf)->input_x)
		{
			math_of_rotation(fdf, i, j);
			j++;
		}
		i++;
	}
	set_color_matrix(fdf);
	return (0);
}

size_t		copy_input_in_matrix(t_fdf **fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*fdf)->input_y)
	{
		j = 0;
		while (j < (*fdf)->input_x)
		{
			(*fdf)->matrix[i][j].x = (*fdf)->input[i][j].x;
			(*fdf)->matrix[i][j].y = (*fdf)->input[i][j].y;
			(*fdf)->matrix[i][j].z = (*fdf)->input[i][j].z;
			(*fdf)->matrix[i][j].color = (*fdf)->input[i][j].color;
			j++;
		}
		i++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_fdf		*fdf;
	int			bpp;
	int			s_l;
	int			endian;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		return (1);
	fdf->input = NULL;
	fdf->matrix = NULL;
	fdf->projection = NULL;
	fdf->image_grid = NULL;
	if (ft_check(ac, av, &fdf) == 1)
		return (ft_error(&fdf));
	if (fill_default_fdf(&fdf, av[1]) == 1)
		return (ft_error(&fdf));
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WINDOW_X, WINDOW_Y, av[1]);
	IMG = mlx_new_image(MLX, IMAGE_X, IMAGE_Y);
	fdf->image_string = mlx_get_data_addr(IMG, &bpp, &s_l, &endian);
	if (fill_grid(&fdf) == 1)
		return (free_all(&fdf));
	re_project(&fdf, fdf->proj);
	mlx_key_hook(WIN, &keyboard, &fdf);
	mlx_loop(MLX);
	return (0);
}
