/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:42:40 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/17 19:32:36 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft.h"

typedef	struct		s_map
{
	char			**rooms;
	char			*start;
	char			*end;
	char			**links;
	int				q_rooms;
	int				ants;
	int				**tab;
}					t_map;


#endif