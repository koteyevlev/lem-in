/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:14:43 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/26 15:49:29 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

void	ft_clean_edge(t_lm **begin, int i, int j, int x)
{
	if (!(*begin)->map)
		return ;
	while ((*begin)->map[i])
	{
		while ((*begin)->map[i][j])
			free(&((*begin)->map[i][j++][x]));
		j = 0;
		i++;
	}
}

int		ft_error(t_lm **begin, t_room *tmp, t_con *tmptwo, char **mas)
{
	int	i;

	i = 0;
	if ((*begin)->rms || (*begin)->con)
	{
		while ((*begin)->rms)
		{
			tmp = ((*begin)->rms->next);
			free((*begin)->rms->name);
			free((*begin)->rms);
			(*begin)->rms = tmp;
		}
		while ((*begin)->con)
		{
			tmptwo = (*begin)->con->next;
			free((*begin)->con);
			(*begin)->con = tmptwo;
		}
		while (mas && mas[i])
			free(mas[i++]);
		free(mas);
		ft_clean_edge(begin, 0, 0, 0);
	}
	ft_putstr("Error\n");
	exit(0);
}

// int		ft_is_valid_con(t_lm *lm, t_lm **begin, char *str, int what)
// {
// 	while (lm->rms && lm->rms->name)
// 	{
// 		if (ft_strncmp(str, lm->rms->name, ft_strindex(str, '-') + 1))
// 		{

// 			break ;
// 		}
// 		lm->rms = lm->rms->next;
// 	}
// 	if (!lm->rms)
// 		return (ft_error(begin, 0, begin, begin));
// 	what = 0;
// 	lm->rms = (*begin)->rms;
// 	while (lm->rms && lm->rms->name)
// 	{
// 		if (ft_strncmp(ft_strstr(str, "-") + 1, lm->rms->name,
// 		ft_strindex(str, '-') + 1))
// 			break ;
// 		lm->rms = lm->rms->next;
// 	}
// 	if (!lm->rms)
// 		return (ft_error(begin, 0, begin, begin));
// 	return (1);
// }

int		ft_lm_creat_con(t_lm **lm, char **str, t_con *begin, t_con **tmp)
{
	t_room	*beginr;

	beginr = (*lm)->rms;
	while ((*lm)->con && (*lm)->con->next)
		(*lm)->con = (*lm)->con->next;
	if (!((*tmp) = (t_con *)malloc(sizeof(t_con))))
		return (ft_error(lm, 0, 0, 0));
	(*lm)->con->next = (*tmp);
	(*tmp)->next = 0;
	(*tmp)->to = ft_lm_room_find(lm, (*lm)->rms, ft_strstr(*str, "-") + 1);
	(*str)[ft_strindex(*str, '-')] = '\0';
	(*tmp)->from = ft_lm_room_find(lm, (*lm)->rms, *str);
	(*lm)->con = begin;
	return (1);
}
