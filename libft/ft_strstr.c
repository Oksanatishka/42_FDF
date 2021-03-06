/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:38:58 by obibik            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:58 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*string1;
	char	*string2;

	string1 = (char *)haystack;
	string2 = (char *)needle;
	if (*string2 == '\0' || string2 == NULL)
		return (string1);
	while (*string1)
	{
		if (is_match(string1, string2))
			return (string1);
		string1++;
	}
	return (NULL);
}
