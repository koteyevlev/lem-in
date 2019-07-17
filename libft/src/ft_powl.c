/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:27:17 by vsanta            #+#    #+#             */
/*   Updated: 2019/06/17 13:38:41 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_powl(long double base, long double exp)
{
	long double	i;
	long double	res;

	i = 0;
	res = 1;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}
