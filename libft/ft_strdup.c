/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if ((new = (char *)malloc(sizeof(*s1) *
				(ft_strlen((char *)s1) + 1))) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	new[i] = '\0';
	return (new);
}
