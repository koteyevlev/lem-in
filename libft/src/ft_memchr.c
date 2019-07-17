/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:19:25 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:11:46 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	tmpc;

	i = 0;
	tmp = (unsigned char*)s;
	tmpc = (unsigned char)c;
	while (n > 0)
	{
		if (tmp[i] == tmpc)
			return ((void*)&s[i]);
		i++;
		n--;
	}
	return (NULL);
}
