/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*rec_elem(t_list *p1, t_list *p2)
{
	t_list	*new_begin;

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

t_list			*ft_lstrev(t_list **lst)
{
	t_list *new_begin;

	if (*lst != NULL)
	{
		if ((*lst)->next != NULL)
		{
			new_begin = rec_elem(*lst, (*lst)->next);
			(*lst)->next = NULL;
			return (new_begin);
		}
		else
			return (*lst);
	}
	else
		return (NULL);
}
