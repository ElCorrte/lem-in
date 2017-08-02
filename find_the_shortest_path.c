/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_shortest_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:31:49 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/21 11:31:50 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

size_t	number_room(t_room *room)
{
	size_t cnt;

	cnt = 0;
	while (room)
	{
		cnt++;
		room = room->next;
	}
	return (cnt);
}

void	write_number(int *number, t_room *room, int distance)
{
	static int this_is;

	if (room->i_was_here == 1)
		return ;
	ft_printf("room %s\n", room->name);
	room->this_is = this_is++;
	room->i_was_here = 1;
	room->distance = room->func_room == 1 ? 0 : (distance + 1);
	number[g_lem_in.cnt] = room->this_is;
	g_lem_in.cnt++;
}

void	write_join(int *number, t_join *join, int distance)
{
	while (join)
	{
		write_number(number, join->room, distance);
		join = join->next;
	}
}

int		find_the_shortest_path(t_room *room)
{
	t_room	*tmp;
	int		*number;
	int		cnt;

	cnt = 0;
	tmp = room;
	number = ft_memalloc(number_room(room));
	while (tmp->func_room != 1)
		tmp = tmp->next;
	write_number(number, tmp, tmp->distance);
	tmp = room;
	while (tmp)
	{
		g_lem_in.new_room = 0;
		if (tmp->this_is == number[cnt])
		{
			write_join(number, tmp->join, tmp->distance);
			g_lem_in.new_room = 1;
			cnt++;
		}
		tmp = tmp->next;
		g_lem_in.new_room == 1 ? tmp = room : 0;
	}
	return (0);
}
