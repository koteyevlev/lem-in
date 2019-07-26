/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:53:42 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/26 16:39:03 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int		ft_isint(char *str)
{
	int		nbr;
	char	*check;
	int		i;

	nbr = ft_atoi(str);
	if (!(check = ft_itoa(nbr)))
		exit(0);
	i = 0;
	while (str[i] && str[i] == check[i])
		i++;
	ft_strdel(&check);
	if (!str[i])
		return (1);
	else
		return (0);
}

void		ft_first_null(t_lm **m)
{
	(*m)->rms = 0;
	(*m)->start = 0;
	(*m)->end = 0;
	(*m)->con = 0;
	(*m)->c_rms = 0;
	(*m)->c_ants = 0;
	(*m)->map = 0;
}

int			ft_is_valid(char **str, int what, t_lm **m, char **mas)
{
	if (what == 1 || what == 6 || what == 5)
	{
		mas = ft_strsplit(*str, ' ');
		if (!mas || !mas[0] || !mas[1] || !mas[2] || mas[3]
			|| !ft_isint(mas[1]) || !ft_isint(mas[2]))
			return (ft_error(m, 0, 0, mas));
		free(*str);
		*str = ft_strnew(ft_strlen(mas[0]));
		ft_strcpy(*str, mas[0]);
		what = 0;
		while (mas && mas[what])
			free(mas[what++]);
		free(mas);
	}
	// else if (what == 2)
	// {
	// }
	return (1);
}

void		ft_start_end(t_lm **m, char **str, int *what)
{
	ft_is_valid(str, *what, m, 0);
	if ((*what == 5 && (*m)->start) || (*what == 6 && (*m)->end))
		ft_error(m, 0, 0, str);
	else if (*what == 5 && !((*m)->start = ft_strnew(ft_strlen(*str))))
		ft_error(m, 0, 0, str);
	else if (*what == 6 && !((*m)->end = ft_strnew(ft_strlen(*str))))
		ft_error(m, 0, 0, str);
	if (*what == 5)
		ft_strcpy((*m)->start, *str);
	if (*what == 6)
		ft_strcpy((*m)->end, *str);
}

void		ft_create_room_con(t_lm **lm, char **str, int what)
{
	ft_is_valid(str, what, lm, 0);
	if (what == 1)
		ft_lm_rooms_create(lm, *str, 0);
	else if (what == 2)
		ft_lm_creat_con(lm, str, (*lm)->con, 0);
}

t_lm		*ft_create_map(void)
{
	t_lm	*m;
	char	*str;
	int		what;

	if (!(m = (t_lm *)malloc(sizeof(t_lm))))
		exit(0);
	what = 0;
	ft_first_null(&m);
	while (get_next_line(0, &str))
	{
		if (!str || !*str)
			continue;
		if (ft_strcmp(str, "##start") == 0 && what == 1 && (what = 5) == 5)
			continue;
		if (ft_strcmp(str, "##end") == 0 && what == 1 && (what = 6) == 6)
			continue;
		what = what != 2 && what != 0 && !ft_strstr(str, " ")
		&& str[0] != '#' ? 2 : what;
		if (!what && ft_isint(str) && (what = 1) == 1)
			m->c_ants = ft_atoi(str);
		else if ((what == 1 || what == 2) && str[0] != '#' && str[0] != 'L')
			ft_create_room_con(&m, &str, what);
		else if (((what == 5 || what == 6)) && str[0] != '#' && str[0] != 'L')
			ft_start_end(&m, &str, &what);
		free(str);
	}
	ft_lm_room_push_back(&m, ft_lm_room_create(&m, m->end));
	ft_lm_room_push_front(&m, ft_lm_room_create(&m, m->start));
	return (m);
}
