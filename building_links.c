/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:49:21 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/20 16:49:22 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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

void	choice_room(t_room **main_room, t_room *head_room, char *room)
{
	t_room *tmp;

	tmp = head_room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room))
			(*main_room)->join = create_new_join(main_room, tmp);
		tmp = tmp->next;
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
	/*while (tmp_start)
	{
		ft_printf("room %s ", tmp_start->name);
		while (tmp_start->join)
		{
			ft_printf(" link %s ", tmp_start->join->room->name);
			tmp_start->join = tmp_start->join->next;
		}
		ft_printf("\n");
		tmp_start = tmp_start->next;
	}*/
	return (0);
}
