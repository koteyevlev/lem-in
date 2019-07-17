/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:19:54 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:12:04 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	i = n;
	while (i > 0)
	{
		tmp_d[i - 1] = tmp_s[i - 1];
		i--;
	}
	return (tmp_d);
}
