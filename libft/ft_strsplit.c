/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		q_words;
	int		i;
	int		j;
	char	**str;
	char	*p1;

	if (s == NULL)
		return (NULL);
	if ((q_words = ft_cntwrds((char *)s, c)) == 0)
		return (NULL);
	if ((str = ft_bldstr((char *)s, q_words, c)) == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words && str[i] != NULL)
	{
		j = -1;
		p1 = ft_fndwrds((char *)s, c, (i + 1));
		while ((p1[++j] != c) && (p1[j] != '\0'))
			str[i][j] = p1[j];
		str[i][j] = '\0';
	}
	return (str);
}
