/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_mtx_lst	*rec_elem(t_mtx_lst *p1, t_mtx_lst *p2)
{
	t_mtx_lst	*new_begin;

	if (p2->next == NULL)
	{
		p2->next = p1;
		return (p2);
	}
	else
	{
		new_begin = rec_elem(p2, p2->next);
		p2->next = p1;
		return (new_begin);
	}
}

t_mtx_lst			*ft_mtx_rev(t_mtx_lst **mlst)
{
	t_mtx_lst *new_begin;

	if (*mlst != NULL)
	{
		if ((*mlst)->next != NULL)
		{
			new_begin = rec_elem(*mlst, (*mlst)->next);
			(*mlst)->next = NULL;
			return (new_begin);
		}
		else
			return (*mlst);
	}
	else
		return (NULL);
}
