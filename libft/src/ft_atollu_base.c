/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:26:16 by pdiedra           #+#    #+#             */
/*   Updated: 2019/07/01 15:38:53 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_char_to_int(char c, int base)
{
	if (c >= 'a' && c <= 'z' && c - 'a' + 10 < base)
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z' && c - 'A' + 10 < base)
		return (c - 'A' + 10);
	else if (ft_isdigit(c) && c - '0' < base)
		return (c - '0');
	else
		return (-1);
}

unsigned long long int	ft_atollu_base(const char *str, int base)
{
	unsigned long long int	num;
	int						i;
	int						step;

	num = 0;
	step = 0;
	i = ft_skipspace(str);
	while (str[i] != 0 && ft_char_to_int(str[i], base) >= 0)
		i++;
	i--;
	while (str[i] && ft_char_to_int(str[i], base) >= 0)
	{
		num = num + ft_char_to_int(str[i], base) * ft_pow(base, step);
		i--;
		step++;
	}
	return (num);
}
