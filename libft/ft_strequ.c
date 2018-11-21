/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 != NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL && s2 != NULL)
		return (0);
	else if (ft_strcmp((char *)s1, (char *)s2) == 0)
		return (1);
	else
		return (0);
}
