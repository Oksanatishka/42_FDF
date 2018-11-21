/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*transfer;
	int		i;

	i = 0;
	transfer = malloc(sizeof(*src) * len);
	if (transfer == NULL)
		return (dst);
	while ((unsigned long)i < (unsigned long)len)
	{
		((unsigned char *)transfer)[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while ((unsigned long)i < (unsigned long)len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)transfer)[i];
		i++;
	}
	free(transfer);
	return (dst);
}
