/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_shortest_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:46:41 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/21 19:46:43 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	create_path(char *name)
{
	t_path *tmp;

	tmp = g_start_path;
	tmp = (t_path *)malloc(sizeof(t_path));
	tmp->name = ft_strdup(name);
	tmp->next = g_start_path;
	g_start_path = tmp;
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
}

void	write_the_shortest_path(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp->func_room != 2)
		tmp = tmp->next;
	create_path(tmp->name);
	while (tmp->next != NULL)
		tmp = find_min_join(tmp->join, tmp->distance);
	while (g_start_path)
	{
		ft_printf("[%s] ", g_start_path->name);
		g_start_path = g_start_path->next;
	}
}