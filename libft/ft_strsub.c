/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*p;
	char			*r;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	p = (char *)s;
	r = (char *)malloc(sizeof(*r) * (len + 1));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = p[start];
		start++;
		i++;
	}
	r[i] = '\0';
	return (r);
}
