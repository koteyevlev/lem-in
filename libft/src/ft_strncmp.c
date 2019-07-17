/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:22:13 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:13:46 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	if (n == 0)
		return (0);
	ns1 = (unsigned char*)s1;
	ns2 = (unsigned char*)s2;
	i = 0;
	while ((i + 1) < n && (ns1[i] && ns2[i]) && (ns1[i] == ns2[i]))
	{
		i++;
	}
	return (ns1[i] - ns2[i]);
}
