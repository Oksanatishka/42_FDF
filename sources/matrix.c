/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:39:09 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:39:09 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** Gets the necessary parameters for applying the
** perspective to the matrix of points.
*/

void	get_perspective(t_win *win)
{
	int		i;
	int		j;
	t_point ***mtx;

	i = -1;
	win->z_max = 0;
	win->z_min = 0;
	mtx = win->xyz_plane;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			if (mtx[i][j]->var_z < win->z_min)
				win->z_min = mtx[i][j]->var_z;
			if (mtx[i][j]->var_z > win->z_max)
				win->z_max = mtx[i][j]->var_z;
		}
	}
	if ((win->z_min + win->z_max) / 2 == 0)
		win->z_ave = 1;
	else
		win->z_ave = (win->z_min + win->z_max) / 2;
}

/*
** Applies the perspective parameters to the matrix of points.
*/

void	apply_fake_perspective(t_win *win)
{
	int		i;
	int		j;
	t_point ***mtx;

	i = -1;
	mtx = win->xyz_plane;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			mtx[i][j]->var_x = mtx[i][j]->var_x *
								((mtx[i][j]->var_z + 300) / (win->z_ave + 300));
			mtx[i][j]->var_y = mtx[i][j]->var_y *
								((mtx[i][j]->var_z + 300) / (win->z_ave + 300));
		}
	}
}

/*
** Applies a rotation matrix on x
*/

void	rot_x(t_win *win)
{
	int		i;
	int		j;
	double	y;
	double	z;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			y = (mtx[i][j])->var_y;
			z = (mtx[i][j])->var_z;
			(mtx[i][j])->var_y = y * cos(win->rotx) - z * sin(win->rotx);
			(mtx[i][j])->var_z = y * sin(win->rotx) + z * cos(win->rotx);
		}
	}
}

/*
** Applies a rotation matrix on y
*/

void	rot_y(t_win *win)
{
	int		i;
	int		j;
	double	x;
	double	z;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			x = (mtx[i][j])->var_x;
			z = (mtx[i][j])->var_z;
			(mtx[i][j])->var_x = x * cos(win->roty) + z * sin(win->roty);
			(mtx[i][j])->var_z = z * cos(win->roty) - x * sin(win->roty);
		}
	}
}

/*
** Applies a rotation matrix on z
*/

void	rot_z(t_win *win)
{
	int		i;
	int		j;
	double	x;
	double	y;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			x = (mtx[i][j])->var_x;
			y = (mtx[i][j])->var_y;
			(mtx[i][j])->var_x = x * cos(win->rotz) - y * sin(win->rotz);
			(mtx[i][j])->var_y = x * sin(win->rotz) + y * cos(win->rotz);
		}
	}
}
