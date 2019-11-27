/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:26:11 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/06 17:42:00 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		ft_error(t_fdf **fdf)
{
	ft_putendl("an error occured\nnote: usage: ./fdf <valid file>");
	free_all(fdf);
	return (1);
}

void		free_array(char ***array)
{
	int		i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
}

int			ft_array_len(char **array)
{
	size_t		out;

	out = 0;
	while (array[out])
		out++;
	return (out);
}

size_t		ft_check(int ac, char **av, t_fdf **fdf)
{
	size_t		i;
	int			fd;
	char		**array_str;
	char		*line;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) <= 0)
		return (1);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		array_str = ft_strsplit(line, ' ');
		if (i == 0)
			(*fdf)->input_x = ft_array_len(array_str);
		else if ((*fdf)->input_x != ft_array_len(array_str))
		{
			free_array(&array_str);
			free(line);
			return (1);
		}
		free_array(&array_str);
		free(line);
		i++;
	}
	(*fdf)->input_y = i;
	return (i == 0 ? 1 : 0);
}

size_t		fill_default_fdf(t_fdf **fdf, char *file_name)
{
	if (reader(file_name, fdf) == 1)
		return (1);
	if (ft_projection_alloc(fdf) == 1)
		return (1);
	if (ft_rotation_alloc(fdf) == 1)
		return (1);
	copy_input_in_matrix(fdf);
	(*fdf)->image_x_input = IMAGE_X / (float)(((*fdf)->input_x) * 2);
	(*fdf)->image_y_input = IMAGE_Y / (float)(((*fdf)->input_y) * 2);
	(*fdf)->altitude_coef = 0.8;
	(*fdf)->angle = 0.523599;
	(*fdf)->max_z = (*fdf)->max_z_input * (*fdf)->altitude_coef;
	(*fdf)->min_z = (*fdf)->min_z_input * (*fdf)->altitude_coef;
	(*fdf)->zoom = 0.95;
	(*fdf)->trans_x = IMAGE_X / 2;
	(*fdf)->trans_y = IMAGE_Y / 2;
	(*fdf)->x_degree = 0.0;
	(*fdf)->z_degree = 0.0;
	(*fdf)->y_degree = 0.0;
	(*fdf)->proj = 0;
	return (0);
}
