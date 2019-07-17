/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:27:17 by vsanta            #+#    #+#             */
/*   Updated: 2019/06/16 15:47:33 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, double exp)
{
	double	i;
	double	res;

	i = 0;
	res = 1;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}
