/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:19:15 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/22 23:17:20 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
