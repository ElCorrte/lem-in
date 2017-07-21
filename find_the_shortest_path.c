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

size_t number_room(t_room *room)
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

void 	write_number(int  **number, int *cnt, t_room **room)
{
	*cnt != 1 ? (*cnt)++ : 0;
	(*room)->this_is = *cnt;
	*number[*cnt] = (*room)->this_is;
}

int 	find_the_shortest_path(t_room **room)
{
	t_room	*tmp;
	int 	*number;
	int 	cnt;

	cnt = 1;
	tmp = *room;
	number = ft_memalloc(number_room(*room));
	while (*room)
	{
		if ((*room)->func_room == 1)
		{
			write_number(&number, &cnt, room);
			*room = tmp;
			break ;
		}
		(*room) = (*room)->next;
	}
	while (*room)
	{
		if ((*room)->this_is == number[cnt])
		{
			while ((*room)->join)
			{
				write_number(&number, &cnt, room);
				(*room)->join = (*room)->join->next;
			}
		}
		(*room) = (*room)->next;
	}
	return (0);
}