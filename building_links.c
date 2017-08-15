/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:49:21 by yzakharc          #+#    #+#             */
/*   Updated: 2017/08/12 18:03:51 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_join	*create_new_join(t_room **head, t_room *low_room)
{
	t_join	*tmp;

	tmp = (*head)->join;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, low_room->name))
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_join *)malloc(sizeof(t_join));
	tmp->room = low_room;
	tmp->next = (*head)->join;
	return (tmp);
}

int		check_same_link(t_room *room, char *name)
{
	t_join *join;

	join = room->join;
	while (join)
	{
		if (ft_strequ(join->room->name, name))
			return (1);
		join = join->next;
	}
	return (0);
}

void	choice_room(t_room **main_room, t_room *head_room, char *room)
{
	t_room *tmp;

	tmp = head_room;
	if (!check_same_link(*main_room, room))
	{
		while (tmp)
		{
			if (ft_strequ(tmp->name, room))
			{
				(*main_room)->join = create_new_join(main_room, tmp);
				return ;
			}
			tmp = tmp->next;
		}
	}
}

int		build_links(t_room **room, t_link *link)
{
	t_room	*tmp_start;
	t_link	*tmp_l;

	tmp_start = *room;
	tmp_l = link;
	while (*room)
	{
		while (tmp_l)
		{
			if (ft_strequ((*room)->name, tmp_l->room_1))
				choice_room(room, tmp_start, tmp_l->room_2);
			if (ft_strequ((*room)->name, tmp_l->room_2))
				choice_room(room, tmp_start, tmp_l->room_1);
			tmp_l = tmp_l->next;
		}
		tmp_l = link;
		(*room) = (*room)->next;
	}
	(*room) = tmp_start;
	return (0);
}
