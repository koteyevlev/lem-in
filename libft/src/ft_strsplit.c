/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:22:51 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/08 17:06:23 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_c_count(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
	}
	return (i);
}

static char			**ft_split_free(char **buf, int j)
{
	while (j >= 0)
	{
		free(buf[j]);
		j--;
	}
	free(buf);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**buf;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	buf = (char**)malloc(sizeof(char*) * (ft_w_count(s, c) + 1));
	if (buf == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			buf[j] = ft_strsub(s, i, ft_c_count(&s[i], c));
			if (buf[j] == NULL)
				return (ft_split_free(buf, j));
			j++;
		}
		i++;
	}
	buf[j] = NULL;
	return (buf);
}
