/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*num_digits_arr(int n, int *digits, int *is_neg)
{
	char	*s;

	*digits = 1;
	*is_neg = 0;
	if (n < 0)
	{
		(*digits)++;
		*is_neg = 1;
	}
	while (n / 10)
	{
		(*digits)++;
		n = n / 10;
	}
	s = (char *)malloc(sizeof(*s) * (*digits + 1));
	if (s == NULL)
		return (NULL);
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		digits;
	int		is_neg;

	s = num_digits_arr(n, &digits, &is_neg);
	if (s == NULL)
		return (NULL);
	i = 0;
	s[digits] = '\0';
	while (--digits >= 0)
	{
		if (n < 0)
		{
			s[0] = '-';
			s[digits] = -(n % 10) + '0';
			n = -(n / 10);
		}
		else if (!(is_neg == 1 && digits == 0))
		{
			s[digits] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (s);
}
