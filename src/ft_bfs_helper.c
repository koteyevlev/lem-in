/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:47:35 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/26 15:40:35 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

t_room		*ft_index_to_room(t_lm *lm, int index)
{
	while ((lm)->rms && index > 0)
		lm->rms = lm->rms->next;
	return (lm->rms);
}

int			ft_room_to_index(t_room *to_find, t_lm *lm)
{
	int		index;

	index = 0;
	while ((lm)->rms && to_find != lm->rms)
	{
		index++;
		lm->rms = lm->rms->next;
	}
	return (index);
}

void		ft_push_back(int index, t_que **q, t_lm **lm)
{
	t_que	*last;
	t_que	*begin;

	if (!(last = (t_que *)malloc(sizeof(t_que))))
		ft_error(lm, 0, 0, 0);
	last->index = index;
	if (!*q)
	{
		(*q) = last;
		return ;
	}
	begin = *q;
	while (begin->next)
		begin = begin->next;
	begin->next = last;
}

void		ft_del_first(t_que **q)
{
	t_que	*begin;

	if (!*q)
		return ;
	begin = (*q)->next;
	free(q);
	*q = begin;
}
