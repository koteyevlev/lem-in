/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:21:56 by vsanta            #+#    #+#             */
/*   Updated: 2019/06/23 15:45:55 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*buf;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		buf[i] = (*f)(s[i]);
		i++;
	}
	buf[i] = 0;
	return (buf);
}
