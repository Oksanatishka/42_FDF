/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:39:09 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:39:09 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** Fourth function called by acquire_xyz, this function makes sure that the
** number of values in every line is the same. If they diverge, returns 0,
** otherwise, return 1, and the caller function can carry on with it's work.
*/

int		lines_are_uniform(char ***mtx, t_win *win)
{
	int i;
	int j;
	int cmp;

	i = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
			j++;
		if (i == 0)
			cmp = j;
		else if (cmp != j)
			return (0);
		i++;
	}
	win->columns = j;
	return (1);
}
