/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mtx_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtx_lst	*ft_get_mtx_lst(int mtx_index, t_mtx_lst *mlst)
{
	int		i;

	i = 0;
	while (mlst)
	{
		if (i == mtx_index)
			return (mlst);
		i++;
		mlst = mlst->next;
	}
	return (NULL);
}
