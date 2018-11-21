/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtx_print(t_mtx_lst *mlst)
{
	int		i;
	int		j;
	int		height;
	int		width;
	char	**matrix;

	height = mlst->height;
	width = mlst->width;
	matrix = mlst->mtx;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			ft_putchar(matrix[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
