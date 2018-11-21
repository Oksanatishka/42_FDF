/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bldstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_bldstr(char *s, int q_words, char c)
{
	char	**str;
	int		i;
	int		*w_sizes;

	if ((w_sizes = ft_wrdsizes(s, q_words, c)) == NULL)
		return (NULL);
	if ((str = (char **)malloc(sizeof(*str) * (q_words + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words)
	{
		if ((str[i] = (char *)malloc(sizeof(**str) * (w_sizes[i] + 1))) == NULL)
			return (ft_free_all(str, i));
	}
	str[i] = NULL;
	free(w_sizes);
	return (str);
}
