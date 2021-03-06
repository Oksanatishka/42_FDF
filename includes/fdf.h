/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:48 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:48 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Libraries.
*/

# include "./../minilibx_macos/mlx.h"
# include "./../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/*
** Macros.
*/

# define W_W 1250
# define W_H 780
# define ANG_INCR 0.20944

/*
** This data structure receives the parsed data from the map.
** ref_ values are based on the file directly
** var_ values are obtained after applying the win-> parrameters
** on the ref_ values.
*/

typedef struct	s_point
{
	double		ref_x;
	double		ref_y;
	double		ref_z;
	double		var_x;
	double		var_y;
	double		var_z;
}				t_point;

/*
** This data structure makes possible the rendering. It contains
** all the parameters that can be applied to the map and also conserve
** information for manipulating the rendering. Every window is a win.
*/

typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	double		lines;
	double		columns;
	double		keycode;
	double		ax;
	double		ay;
	double		az;
	double		osx;
	double		osy;
	double		rotx;
	double		roty;
	double		rotz;
	double		z_max;
	double		z_min;
	double		z_ave;
	double		color_incr;
	int			color_pal;
	int			perspective;
	t_point		***xyz_plane;
}				t_win;

/*
** Functions of the main.c file
*/

int				main(int ac, char **av);
t_win			*init_window(char *arg);
void			update_pts_vars(t_win *win);
void			free_mtx_pts(t_point ***pts_mtx, double lines, double columns);

/*
** Functions of the keys.c file
*/

int				key_hook(int keycode, t_win *win);
void			act_on_key(t_win *win);
void			clear_img(t_win *win);

/*
** Functions of the ext_keys.c file
*/

void			chng_ang_all(t_win *win);
void			chng_axs_par(t_win *win);
void			chng_pos_lin(t_win *win);
void			chng_pos_ang(t_win *win);
void			chng_persp(t_win *win);

/*
** Functions of the matrix.c file
*/

void			rot_x(t_win *win);
void			rot_y(t_win *win);
void			rot_z(t_win *win);
void			get_perspective(t_win *win);
void			apply_fake_perspective(t_win *win);

/*
** Functions of the read_map.c file
*/

t_list			*read_map_to_lst(int fd, t_win *win);
char			***chr_mtx_3d(t_list *lst, int lst_count);
t_point			***pts_mtx_3d(char ***chr_mtx, int line_count,
													int nbr_count);
int				acquire_xyz(t_win **win, char *arg);
void			free_mtx_chr(char ****chr_mtx, double lines, double columns);

/*
** Functions of the checks.c file
*/

int				lines_are_uniform(char ***mtx, t_win *win);

/*
** Functions of the prints.c file
*/

void			error(void);
void			plot_points(t_win *win);
void			print_commands(t_win *win);

/*
** Functions of the colors.c file
*/

void			set_color_incr(t_win *win);
int				set_color(t_win *win, double z);
void			chng_color(t_win *win);

/*
** Functions of the plot_line.c file
*/

void			plot_line(t_win *win, t_point *p0, t_point *p1);
void			plot_line_action(double *coords, t_win *win);
void			plot_line_assigns(t_point *p0, t_point *p1, double *coords,
																int *ctrls);
#endif
