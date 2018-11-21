/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *odst;

	odst = dst;
	while (n > 0)
	{
		((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (odst);
}
