/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:02:05 by crfernan          #+#    #+#             */
/*   Updated: 2019/03/06 18:23:40 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libc.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WINDOW_X 1500
# define WINDOW_Y 1000
# define IMAGE_X 1500.0
# define IMAGE_Y 1000.0

# define MOVE_STEP 20
# define DEGREE_STEP 0.104719

# define R_OF_COL(x) (x / 0x10000)
# define G_OF_COL(x) (x / 0x100 % 0x100)
# define B_OF_COL(x) (x % 0x100 % 0x100)

# define MID_R(x, y) ((R_OF_COL(x) / 2 + R_OF_COL(y) / 2) * 0x10000)
# define MID_G(x, y) ((G_OF_COL(x) / 2 + G_OF_COL(y) / 2) * 0x100)
# define MID_B(x, y) ((B_OF_COL(x) / 2 + B_OF_COL(y) / 2))

# define MID_COLOR(x, y) ((MID_R(x, y) + MID_G(x, y) + MID_B(x, y)))

# define PI 3.141592653

# define WIN fdf->window
# define IMG fdf->image
# define COL fdf->color
# define NBR fdf->nbr
# define MLX fdf->mlx

# define POINTERS (*fdf)->mlx, (*fdf)->window

# define X_DEG (*fdf)->x_degree
# define Y_DEG (*fdf)->y_degree
# define Z_DEG (*fdf)->z_degree

# define VIEW_DEG (*fdf)->angle

# define X_INP (*fdf)->input[i][j].x
# define Y_INP (*fdf)->input[i][j].y
# define Z_INP (*fdf)->input[i][j].z * (*fdf)->altitude_coef

# define X_MAT (*fdf)->matrix[i][j].x
# define Y_MAT (*fdf)->matrix[i][j].y
# define Z_MAT (*fdf)->matrix[i][j].z

# define X_PRO (*fdf)->projection[i][j].x
# define Y_PRO (*fdf)->projection[i][j].y
# define Z_PRO (*fdf)->projection[i][j].z

# define PROJECTION (*fdf)->projection

# define X_TRANS (*fdf)->trans_x
# define Y_TRANS (*fdf)->trans_y

# define Z_MIDDLE ((fabs((*fdf)->max_z) - fabs((*fdf)->min_z)) / 2.0)
# define Y_MIDDLE (*fdf)->middle_y

# define X_ZOOM (*fdf)->image_x_input
# define Y_ZOOM (*fdf)->image_y_input
# define Z_ZOOM (*fdf)->altitude_coef

# define MAX_X (*fdf)->input_x
# define MAX_Y (*fdf)->input_y

# define DX (point_one.x - point_zero.x)
# define DY (point_one.y - point_zero.y)

# define COLOR_TOP (*fdf)->color_top
# define COLOR_BUT (*fdf)->color_bottom

typedef struct		s_matrix
{
	float			x;
	float			y;
	float			z;
	unsigned int	color;
}					t_matrix;

typedef struct		s_fdf
{
	t_matrix		**input;
	t_matrix		**matrix;
	t_matrix		**projection;
	int				input_x;
	int				input_y;
	unsigned int	color_top;
	unsigned int	color_bottom;
	float			image_x_input;
	float			image_y_input;
	void			*window;
	void			*mlx;
	void			*image;
	char			*image_string;
	unsigned int	**image_grid;
	float			trans_x;
	float			trans_y;
	float			x_degree;
	float			y_degree;
	float			z_degree;
	int				max_z_input;
	int				min_z_input;
	float			max_z;
	float			min_z;
	float			max_y;
	float			min_y;
	float			zoom;
	float			altitude_coef;
	float			angle;
	int				proj;
}					t_fdf;

/*
** ALLOCATION
*/
size_t				ft_projection_alloc(t_fdf **fdf);
size_t				ft_rotation_alloc(t_fdf **fdf);
size_t				fill_grid(t_fdf **fdf);
size_t				free_all(t_fdf **fdf);
size_t				ft_input_alloc(t_fdf **fdf);

/*
** HELPERS
*/
size_t				ft_check(int ac, char **av, t_fdf **fdf);
size_t				ft_error(t_fdf **fdf);
void				free_array(char ***array);
int					ft_array_len(char **array);
size_t				fill_default_fdf(t_fdf **fdf, char *file_name);

/*
** MAIN
*/
void				set_color_matrix(t_fdf **fdf);
size_t				copy_input_in_matrix(t_fdf **fdf);
size_t				rotation(t_fdf **fdf);
void				math_of_rotation(t_fdf **fdf, int i, int j);

/*
** READER
*/
size_t				reader(char *file, t_fdf **fdf);
t_matrix			**ft_matrix_alloc(t_fdf **fdf);
void				set_max_min(t_fdf **fdf, int i, int j);
size_t				find_min_max_z(t_fdf **fdf);
void				save_input(t_fdf **fdf, int i, int j, char **somehow);

/*
** IMAGE_MANIPULATION
*/
void				fill_image(char **image_string, unsigned int **grid);
size_t				draw_line(t_matrix point_zero, t_matrix point_one,
					t_fdf **fdf);
size_t				bohemian_algorithm(t_fdf **fdf);

/*
** PROJECTIONS
*/
size_t				fill_parallel_projection_oh(t_fdf **fdf);
size_t				fill_parallel_projection(t_fdf **fdf);
size_t				fill_isometric_projection(t_fdf **fdf);
size_t				fill_isometric_projection_2(t_fdf **fdf);
size_t				re_project(t_fdf **fdf, int proj);

/*
** KEYS_1 and KEYS_2
*/
int					keyboard(int key, t_fdf **fdf);
void				key_esc(int key, t_fdf **fdf);
void				key_rotation(int key, t_fdf **fdf);
void				key_trans(int key, t_fdf **fdf);
void				key_altitude(int key, t_fdf **fdf);
void				key_change_projection(int key, t_fdf **fdf);
void				key_zoom(int key, t_fdf **fdf);
void				key_angle(int key, t_fdf **fdf);
void				key_color(int key, t_fdf **fdf);

#endif
