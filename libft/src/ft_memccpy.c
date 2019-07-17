/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:19:20 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:11:43 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		if (tmp_s[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
