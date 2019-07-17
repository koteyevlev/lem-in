/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:04:26 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/10 20:35:10 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		sign;
	char	nbr1[11];
	char	*nbr2;

	i = 0;
	j = 0;
	sign = n >= 0 ? 1 : -1;
	while (sign * n > 9 || sign * n < 0)
	{
		nbr1[i++] = '0' + sign * (n % 10);
		n = n / 10;
	}
	nbr1[i++] = '0' + sign * n;
	if (sign < 0)
		nbr1[i++] = '-';
	if ((nbr2 = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	nbr2[i] = '\0';
	while (i--)
		nbr2[i] = nbr1[j++];
	return (nbr2);
}
