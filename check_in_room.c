/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:27 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/12 15:12:28 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		write_name_room(char *line, int *cnt)
{
	while (ft_isprint(line[*cnt]) && line[*cnt] != 32)
		(*cnt)++;
	g_lem_in.room = ft_strnew((size_t)*cnt);
	ft_strncpy(g_lem_in.room, line, (size_t)*cnt);
	if (ft_strchr(g_lem_in.room, '-'))
		return (0);
	return (1);
}

int		add_new_room_in_list(char *room, t_room **head, int func_room)
{
	t_room	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room) ||
				((tmp->x == g_lem_in.x_room && tmp->y == g_lem_in.y_room)))
			return (0);
		tmp = tmp->next;
	}
	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->name = ft_strdup(room);
	tmp->x = g_lem_in.x_room;
	tmp->y = g_lem_in.y_room;
	tmp->func_room = func_room;
	tmp->next = (*head);
	(*head) = tmp;
	return (1);
}

int		create_room(char *line, t_room **head, int func_room)
{
	int 	cnt;
	int 	len;

	cnt = 0;
	if (!write_name_room(line, &cnt))
		return (0);
	if ((ft_isdigit(line[cnt + 1])) ||
			(line[cnt + 1] == '-' && ft_isdigit(line[cnt + 2])))
	{
		g_lem_in.x_room = ft_atoi(line + (cnt + 1));
		len = len_value(g_lem_in.x_room);
		if ((line[cnt + len + 1] == 32 && ft_isdigit(line[cnt + len + 2])) ||
				(line[cnt + len + 2] == '-' && ft_isdigit(line[cnt + len + 3])))
			g_lem_in.y_room = ft_atoi(line + cnt + len + 1);
		else
			return (0);
		if (!add_new_room_in_list(g_lem_in.room, head, func_room))
			return (0);
		write_map(line);
	}
	else
		return (0);
	return (1);
}

int 	create_start_or_end(char **line, t_room **head)
{
	int room;

	room = 0;
	if (ft_strequ(*line + 2, "start"))
	{
		room = 1;
		g_lem_in.start_cnt++;
	}
	else if (ft_strequ(*line + 2, "end"))
	{
		room = 2;
		g_lem_in.end_cnt++;
	}
	if (room != 0)
	{
		write_map(*line);
		//ft_strdel(line);
		get_next_line(g_fd, line);
		this_is_comment_or_command(line);
		if (!create_room(*line, head, room == 1 ? 1 : 2))
			return (0);
	}
	else
		return (0);
	return (1);
}

int 	find_room(char *line, t_room *head)
{
	line ? ft_strdel(&line) : 0;
	while (get_next_line(g_fd, &line))
	{
		this_is_comment_or_command(&line);
		if (ft_isprint(*line) && *line != 'L' && *line != '#' && *line != 32)
		{
			if (!create_room(line, &head, 0))
				return (0);
		}
		else if (*line == '#' && *(line + 1) == '#')
		{
			if (!create_start_or_end(&line, &head))
				return (0);
		}
		ft_strdel(&line);
	}
	if (g_lem_in.start_cnt != 1 || g_lem_in.end_cnt != 1)
		return (0);
	return (1);
}