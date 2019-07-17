/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:59:58 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/17 20:14:12 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

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

void		ft_first_null(t_map **m)
{
	(*m)->rooms = 0;
	(*m)->start = 0;
	(*m)->end = 0;
	(*m)->links = 0;
	(*m)->q_rooms = 0;
	(*m)->ants = 0;
	(*m)->tab = 0;
}

void		ft_delete_map(t_map **m)
{
	int		index;

	free((*m)->start);
	free((*m)->end);
	index = 0;
	while ((*m)->rooms[index])
	{
		free((*m)->rooms[index]);
		index++;
	}
	free((*m)->rooms);
	index = 0;
	while ((*m)->links[index])
	{
		free((*m)->links[index]);
		index++;
	}
	free((*m)->links);
	index = 0;
	while ((*m)->tab[index])
	{
		free((*m)->tab[index]);
		index++;
	}
	free((*m)->tab);
}

void		ft_start_end(t_map **m, char *str, int *what)
{
	if ((*what == 5 && (*m)->start) || (*what == 6 && (*m)->end))
	{
		ft_putstr("Error\n");
		ft_delete_map(m);
		exit(0);
	}
	else if (*what == 5 && !((*m)->start = ft_strnew(ft_strlen(str))))
	{
		ft_putstr("Error\n");
		ft_delete_map(m);
		exit(0);
	}
	else if (*what == 6 && !((*m)->end = ft_strnew(ft_strlen(str))))
	{
		ft_putstr("Error\n");
		ft_delete_map(m);
		exit(0);
	}
	if (*what == 5)
		ft_strcpy((*m)->start, str);
	if (*what == 6)
		ft_strcpy((*m)->end, str);
}

char		**ft_cpy_plus(char **orig, char *str)
{
	char	**res;
	int		index;

	index = 0;
	while (orig && orig[index])
		index++;
	res = (char **)malloc(sizeof(char *) * (index + 2));
	res[index + 1] = 0;
	index = 0;
	while (orig && orig[index])
	{
		res[index] = ft_strnew(ft_strlen(orig[index]));
		ft_strcpy(res[index], orig[index]);
		index++;
	}
	res[index] = ft_strnew(ft_strlen(str));
	ft_strcpy(res[index], str);
	return (res);
}

void		ft_realloc(t_map **m, char *str, int what, char **mas)
{
	int		index;

	index = 0;
	if (what == 1)
	{
		mas = ft_cpy_plus((*m)->rooms, str);
		while ((*m)->rooms && (*m)->rooms[index])
		{
			free((*m)->rooms[index]);
			index++;
		}
		(*m)->q_rooms++;
		free((*m)->rooms);
		(*m)->rooms = mas;
	}
	else if (what == 2)
	{
		mas = ft_cpy_plus((*m)->links, str);
		while ((*m)->links && (*m)->links[index])
		{
			free((*m)->links[index]);
			index++;
		}
		free((*m)->links);
		(*m)->links = mas;
	}
}

t_map		*create_map(void)
{
	t_map	*m;
	char	*str;
	int		what;

	if(!(m = (t_map *)malloc(sizeof(t_map))))
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
		what = what != 0 && !ft_strstr(str, " ") && str[0] != '#' ? 2 : what;
		if (!what && ft_isint(str) && (what = 1) == 1)
			m->ants = ft_atoi(str);
		else if (what == 1 || what == 2)
			ft_realloc(&m, str, what, 0);
		else if ((what == 5 || what == 6))
			ft_start_end(&m, str, &what);
		free(str);
	}
	return (m);
}

int			main(void)
{
	t_map	*m;

	m = create_map();
	return (0);
}