/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:33:38 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/26 16:42:44 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

t_room			*ft_lm_room_create(t_lm **lm, char *str)
{
	t_room	*new;
	char	*news;

	if ((new = (t_room*)malloc(sizeof(t_room))) == NULL)
		ft_error(lm, 0, 0, 0);
	if (!(news = ft_strnew(ft_strlen(str))))
		ft_error(lm, 0, 0, 0);
	new->index = -1;
	new->parent = 0;
	new->name = ft_strcpy(news, str);;
	new->next = NULL;
	return (new);
}

void			ft_lm_room_push_back(t_lm **lm, t_room *new)
{
	t_room	*last;

	if ((*lm)->rms == NULL)
		(*lm)->rms = new;
	else
	{
		last = (*lm)->rms;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void			ft_lm_room_push_front(t_lm **lm, t_room *new)
{
	if ((*lm)->rms == NULL)
		(*lm)->rms = new;
	else
	{
		new->next = (*lm)->rms;
		(*lm)->rms = new;
	}
}

// t_room			*ft_lm_room_push_val(t_room **rooms, t_room rm_tmp, int stat)
// {
// 	t_room *new;

// 	if ((new = ft_lm_room_create(rm_tmp)) == NULL)
// 		return (NULL);
// 	if (stat < 0)
// 		ft_lm_room_push_back(rooms, new);
// 	else
// 		ft_lm_room_push_front(rooms, new);
// 	return (*rooms);
// }

t_room		*ft_lm_room_find(t_lm **lm, t_room *rooms, char *name)
{
	while (rooms && rooms->name)
	{
		if (ft_strcmp(rooms->name, name) == 0)
			return (rooms);
		rooms = rooms->next;
	}
	ft_error(lm, 0, 0, 0);
	return (0);
}

void		ft_lm_rooms_create(t_lm **lm, char *str)
{
	t_room	*rm_tmp;

	rm_tmp = ft_lm_room_create(lm, str);
	ft_lm_room_push_back(lm, rm_tmp);
}
