/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:21:08 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:12:58 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char*)s1;
	ns2 = (unsigned char*)s2;
	i = 0;
	while ((ns1[i] && ns2[i]) && (ns1[i] == ns2[i]))
	{
		i++;
	}
	return (ns1[i] - ns2[i]);
}
