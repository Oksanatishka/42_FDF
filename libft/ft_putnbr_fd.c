/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n / 10)
			ft_putnbr_fd(-(n / 10), fd);
		n = -(n % 10) + '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		if (n / 10)
			ft_putnbr_fd(n / 10, fd);
		n = n % 10 + '0';
		ft_putchar_fd(n, fd);
	}
}
