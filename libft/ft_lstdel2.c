/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel2(t_list **alst)
{
	t_list **flwr;
	t_list *aux;

	flwr = alst;
	aux = *alst;
	while (*flwr != NULL)
	{
		free((*flwr)->content);
		aux = (*flwr)->next;
		free(*flwr);
		*flwr = aux;
	}
	if (flwr != NULL)
		free(*flwr);
	*alst = NULL;
}
