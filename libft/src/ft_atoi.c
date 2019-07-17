/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:12:11 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/09 17:38:33 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			neg;

	num = 0;
	i = ft_skipspace(str);
	neg = 1;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		if (num != -2147483648 && num < 0 && neg == -1)
			return (0);
		else if (num != -2147483648 && num < 0)
			return (-1);
		i++;
	}
	return (num * neg);
}
