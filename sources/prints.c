/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:39:09 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:39:09 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** This function is there to make sure the line printing algorithm and the
** color setter work together to give the ilusion of deepness. This function
** call makes sure the first point has an equal or lower var_z than the second.
*/

void	plot_growing_point(t_win *win, t_point ***mtx, int i, int j)
{
	if (j + 1 < win->columns)
	{
		if ((mtx[i][j])->var_z < (mtx[i][j + 1])->var_z)
			plot_line(win, mtx[i][j], mtx[i][j + 1]);
		else
			plot_line(win, mtx[i][j + 1], mtx[i][j]);
	}
	if (i + 1 < win->lines)
	{
		if ((mtx[i][j])->var_z < (mtx[i + 1][j])->var_z)
			plot_line(win, mtx[i][j], mtx[i + 1][j]);
		else
			plot_line(win, mtx[i + 1][j], mtx[i][j]);
	}
}

/*
** This function is called whenever the window needs to be refreshed. It
** updates the values of the map according to the projections and other
** parameters, as well as rotations. Once the struct window is updated,
** it starts drawing lines between the points. It iterates the map drawing
** the lines in a simple patter, from the upper left point to it's
** neighboors to the right and down.
*/

void	plot_points(t_win *win)
{
	int		i;
	int		j;
	t_point	***mtx;

	update_pts_vars(win);
	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
			plot_growing_point(win, mtx, i, j);
	}
}

/*
** To show the user how to interact with the program.
*/

void	print_commands(t_win *win)
{
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 500, 0x08f020,
					"'ESC' - exit");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 520, 0x08f020,
					"'P' - change projection");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 540, 0x08f020,
					"'Q' | 'R' - change x axis");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 560, 0x08f020,
					"'W' | 'T' - change y axis");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 580, 0x08f020,
					"'E' | 'Y' - change z axis");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 600, 0x08f020,
					"'G' | 'H' - change zoom");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 620, 0x08f020,
					"'SPACE' - reset");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 640, 0x08f020,
					"'4' | '1' - rotate on x");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 660, 0x08f020,
					"'5' | '2' - rotate on y");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 680, 0x08f020,
					"'6' | '3' - rotate on z");
	mlx_string_put(win->m_p, win->w_p, W_W / 55, W_H / 55 + 700, 0x08f020,
					"'C' | 'V' - change colors");
}

/*
** The sixth function called by acquire_xyz, signals error if the number
** of values per line is not coherent. This type of error is the only one
** I could think of that could make the program crash. Any other type
** could make it work in an undesired way, but that would still be acceptable.
*/

void	error(void)
{
	ft_putendl("Error! The number of values per line is not coherent.");
	exit(0);
}
