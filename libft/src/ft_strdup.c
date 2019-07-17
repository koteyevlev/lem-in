/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:21:22 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:13:09 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	if (dest)
		dest = ft_strcpy(dest, s1);
	else
		dest = ((void *)0);
	return (dest);
}
