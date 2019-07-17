/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:21:46 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:13:25 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	j = 0;
	if (size <= d_len)
		return (s_len + size);
	while (dst[i] != 0 && i < size - 1)
		i++;
	while (src[j] != 0 && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (d_len + s_len);
}
