/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:25:59 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 18:29:02 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		ft_input_alloc(t_fdf **fdf)
{
	int		i;

	if (!((*fdf)->input = (t_matrix**)malloc(sizeof(t_matrix*) *
		((*fdf)->input_y + 1))))
		return (1);
	i = 0;
	while (i < (*fdf)->input_y)
	{
		if (!(((*fdf)->input[i] =
		(t_matrix*)malloc(sizeof(t_matrix) * ((*fdf)->input_x)))))
			return (1);
		i++;
	}
	(*fdf)->input[(*fdf)->input_y] = NULL;
	return (0);
}

size_t		ft_projection_alloc(t_fdf **fdf)
{
	int		i;

	if (!((*fdf)->projection = (t_matrix**)malloc(sizeof(t_matrix*) *
	((*fdf)->input_y + 1))))
		return (1);
	i = 0;
	while (i < (*fdf)->input_y)
	{
		if (!(((*fdf)->projection[i] =
		(t_matrix*)malloc(sizeof(t_matrix) * ((*fdf)->input_x)))))
			return (1);
		i++;
	}
	(*fdf)->projection[(*fdf)->input_y] = NULL;
	return (0);
}

size_t		fill_grid(t_fdf **fdf)
{
	int		i;

	if (!((*fdf)->image_grid = (unsigned int**)malloc(sizeof(unsigned int*)
		* IMAGE_Y)))
		return (1);
	i = -1;
	while (++i < IMAGE_Y)
		if (!((*fdf)->image_grid[i] = (unsigned int*)malloc(sizeof(unsigned int)
			* IMAGE_X)))
			return (1);
	(*fdf)->image_grid[(int)IMAGE_Y] = NULL;
	return (0);
}

size_t		ft_rotation_alloc(t_fdf **fdf)
{
	int		i;

	if (!((*fdf)->matrix = (t_matrix**)malloc(sizeof(t_matrix*) *
		((*fdf)->input_y + 1))))
		return (1);
	i = 0;
	while (i < (*fdf)->input_y)
	{
		if (!(((*fdf)->matrix[i] =
		(t_matrix*)malloc(sizeof(t_matrix) * ((*fdf)->input_x)))))
			return (1);
		i++;
	}
	(*fdf)->matrix[(*fdf)->input_y] = NULL;
	return (0);
}

size_t		free_all(t_fdf **fdf)
{
	int		i;

	i = -1;
	while ((*fdf)->input != NULL && ++i < (*fdf)->input_y)
		free(((*fdf)->input[i]));
	i = -1;
	while ((*fdf)->matrix != NULL && ++i < (*fdf)->input_y)
		free(((*fdf)->matrix[i]));
	i = -1;
	while ((*fdf)->projection != NULL && ++i < (*fdf)->input_y)
		free(((*fdf)->projection[i]));
	i = -1;
	while ((*fdf)->image_grid != NULL && ++i < IMAGE_Y)
		free(((*fdf)->image_grid[i]));
	if ((*fdf)->input)
		free((*fdf)->input);
	if ((*fdf)->matrix)
		free((*fdf)->matrix);
	if ((*fdf)->projection)
		free((*fdf)->projection);
	if ((*fdf)->image_grid)
		free((*fdf)->image_grid);
	free(*fdf);
	return (1);
}
