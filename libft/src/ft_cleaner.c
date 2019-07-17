/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:54:21 by vsanta            #+#    #+#             */
/*   Updated: 2019/06/17 23:19:25 by Alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(void ***array)
{
	unsigned char	**tmp;
	int				i;

	tmp = (unsigned char**)*array;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
}

int			ft_cleaner(void **ar1, void ***ar2, void ****ar3)
{
	int i;

	i = 0;
	if (ar1 && *ar1)
	{
		free(*ar1);
		*ar1 = NULL;
	}
	if (ar2 && **ar2)
		ft_free_array(ar2);
	if (ar3 && ***ar3)
	{
		while ((*ar3)[i])
		{
			ft_free_array(&((*ar3)[i]));
			i++;
		}
		free(*ar3);
		*ar3 = NULL;
	}
	return (0);
}
