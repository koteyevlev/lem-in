/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:17:32 by vsanta            #+#    #+#             */
/*   Updated: 2019/06/16 15:57:39 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delint(int n)
{
	int i;
	int len;
	int del;

	i = 0;
	del = 1;
	len = ft_digitcount(n);
	while (i < len - 1)
	{
		del = del * 10;
		i++;
	}
	return (del);
}
