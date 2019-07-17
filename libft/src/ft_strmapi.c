/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:22:02 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:13:38 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*buf;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		buf[i] = (*f)(i, s[i]);
		i++;
	}
	buf[i] = 0;
	return (buf);
}
