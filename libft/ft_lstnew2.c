/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew2(char *content)
{
	t_list	*r;

	r = (t_list *)malloc(sizeof(*r));
	if (r == NULL)
		return (NULL);
	if (content == NULL)
	{
		r->content = NULL;
		r->content_size = 0;
	}
	else
	{
		r->content = ft_strdup(content);
		if (r->content == NULL)
		{
			free(r);
			return (NULL);
		}
		r->content_size = ft_strlen(content) + 1;
	}
	r->next = NULL;
	return (r);
}
