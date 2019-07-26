/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:26:14 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/26 16:41:44 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int		ft_check_link(t_lm *lm, int i, int j, int x)
{
	char	*fst;
	char	*sec;

	while (lm->rms)
	{
		if (i-- == x)
			fst = lm->rms->name;
		if (j-- == 0)
			sec = lm->rms->name;
		if (i <= 0 && j <= 0)
			break ;
		lm->rms = lm->rms->next;
	}
	while (lm->con)
	{
		if (!(ft_strcmp(lm->con->from->name, fst) && !ft_strcmp(
		lm->con->to->name, sec)) || !(ft_strcmp(lm->con->to->name, fst) &&
		!ft_strcmp(lm->con->from->name, sec)))
			return (1);
		lm->con = lm->con->next;
	}
	return (0);
}

int		ft_create_matrix(t_lm **lm, t_node ***tmp, int i, int j)
{
	if (!(tmp = (t_node ***)malloc(sizeof(t_node **) * ((*lm)->c_rms + 1))))
		ft_error(lm, 0, 0, 0);
	tmp[(*lm)->c_rms] = 0;
	while (tmp[i])
	{
		if (!(tmp[i] = (t_node **)malloc(sizeof(t_node *)
		* ((*lm)->c_rms + 1))))
			ft_error(lm, 0, 0, 0);
		while (tmp[i][j])
		{
			if (!(tmp[i][j] = (t_node *)malloc(sizeof(t_node)
			* ((*lm)->c_rms + 1))))
				ft_error(lm, 0, 0, 0);
			tmp[i][j]->val = -1;
			if (i == j)
				tmp[i][j]->val = 0;
			if (i != j && ft_check_link(*lm, i, j, 0) == 1)
				tmp[i][j]->val = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
