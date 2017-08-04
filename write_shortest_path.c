/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_shortest_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:46:41 by yzakharc          #+#    #+#             */
/*   Updated: 2017/08/04 19:11:02 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_path(char *name)
{
	t_path *tmp;

	tmp = (t_path *)malloc(sizeof(t_path));
	tmp->name = ft_strdup(name);
	tmp->ant_came = 0;
	tmp->next = NULL;
	if (g_start_path == NULL)
	{
		g_start_path = tmp;
		g_end_path = tmp;
		return ;
	}
	g_end_path->next = tmp;
	tmp->prev = g_end_path;
	g_end_path = tmp;
}

t_room	*find_min_join(t_join *join, int distance)
{
	while (join)
	{
		if (join->room->distance < distance && join->room->this_is != -1)
		{
			create_path(join->room->name);
			return (join->room);
		}
		join = join->next;
	}
	return (NULL);
}

void	write_the_shortest_path(t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->func_room != 2)
		tmp = tmp->next;
	create_path(tmp->name);
	while (tmp->func_room != 1)
	{
		if (tmp->join)
		{
			tmp = find_min_join(tmp->join, tmp->distance);
			if (tmp == NULL && ft_printf(RED"ERROR\n"RESET))
				exit(0);
		}
		else
		{
			ft_printf(RED"ERROR\n"RESET);
			exit(0);
		}
	}
	g_end_path->ant_came = g_lem_in.ant;
	g_lem_in.len_room = len_path();
	g_lem_in.cnt = 0;
}
