/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:57 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:57 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		s_size;

	s_size = ft_strlen((char *)s);
	ptr = (char *)s;
	if (ptr[s_size] == (unsigned char)c)
		return (ptr + s_size);
	while (--s_size >= 0)
	{
		if (ptr[s_size] == (unsigned char)c)
			return (ptr + s_size);
	}
	return (NULL);
}
