/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incr_n_trans.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If the main buffer, or return array, is not big enough to accomodate all the
** reding from the file, a new bigger one will be allocated, the content will
** be transfered to it, and the older smaller array will be freed.
*/

char	*ft_incr_n_trans(char *str, int *size)
{
	int		i;
	int		new_size;
	char	*temp;

	new_size = *size * 2;
	temp = malloc(sizeof(*str) * new_size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	*size = new_size;
	free(str);
	return (temp);
}
