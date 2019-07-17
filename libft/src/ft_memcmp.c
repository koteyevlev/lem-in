/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:19:33 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:11:50 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	if (n == 0)
		return (0);
	ns1 = (unsigned char*)s1;
	ns2 = (unsigned char*)s2;
	i = 0;
	while ((i + 1) < n && (ns1[i] == ns2[i]))
	{
		i++;
	}
	return (ns1[i] - ns2[i]);
}
