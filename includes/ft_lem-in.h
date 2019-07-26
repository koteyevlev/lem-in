/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem-in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:05:30 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/26 16:42:58 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft.h"

typedef struct		s_room
{
	int				index;
	struct s_room	*parent;
	char			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_con
{
	t_room			*from;
	t_room			*to;
	struct s_con	*next;
}					t_con;

typedef struct		s_node
{
	int				val;
}					t_node;

typedef struct		s_que
{
	int				index;
	struct s_que	*next;
}					t_que;

typedef struct		s_lm
{
	int				c_ants;
	int				c_rms;
	char			*start;
	char			*end;
	t_room			*rms;
	t_con			*con;
	t_node			***map;
}					t_lm;

int					ft_lm_creat_con(t_lm **lm, char **str, t_con *begin, t_con **tmp);
int					ft_error(t_lm **begin, t_room *tmp, t_con *tmptwo, char **mas);
void				ft_clean_edge(t_lm **begin, int i, int j, int x);
void				ft_lm_rooms_create(t_lm **lm, char *str);
t_room				*ft_lm_room_find(t_lm **lm, t_room *rooms, char *name);
void				ft_lm_room_push_front(t_lm **lm, t_room *new);
void				ft_lm_room_push_back(t_lm **lm, t_room *new);
t_room				*ft_lm_room_create(t_lm **lm, char *str);
int					ft_isint(char *str);
void				ft_first_null(t_lm **m);
t_lm				*ft_create_map(void);
int					ft_create_matrix(t_lm **lm, t_node ***tmp, int i, int j);
t_room				*ft_index_to_room(t_lm *lm, int index);
int					ft_room_to_index(t_room *to_find, t_lm *lm);
void				ft_push_back(int index, t_que **q, t_lm **lm);
void				ft_del_first(t_que **q);

#endif
