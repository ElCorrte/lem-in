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

char 	*write_name_room(char *line, int len)
{
	char *new;

	new = ft_strnew((size_t)len);
	ft_strncpy(new, line, (size_t)len);
	return (new);
}

void	add_new_room_in_list(char *room, int x, int y, t_room **head)
{
	t_room	*tmp;

	tmp = *head;
	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->name = room;
	tmp->x = x;
	tmp->y = y;
	tmp->next = (*head);
	(*head) = tmp;
}

int		create_room(char *line, t_room **head)
{
	int 	cnt;
	int		x;
	int 	y;
	int 	len;

	cnt = 0;
	while (ft_isprint(line[cnt]) && line[cnt] != 32)
		cnt++;
	if (ft_strchr(line, '-'))
		return (0);
	if (ft_isdigit(line[cnt + 1]))
	{
		x = ft_atoi(line + (cnt + 1));
		len = len_value(x);
		if (line[cnt + len + 1] == 32 && ft_isdigit(line[cnt + len + 2]))
			y = ft_atoi(line + cnt + len + 1);
		else
			return (0);
		add_new_room_in_list(write_name_room(line, cnt), x, y, head);
		write_map(line);
	}
	else
		return (0);
	return (1);
}

int 	create_start_or_end(char **line)
{
	int room;

	room = 0;
	if (ft_strequ(*line + 2, "start"))
		room = 1;
	else if (ft_strequ(*line + 2, "end"))
		room = 2;
	if (room != 0)
	{
		write_map(*line);
		//ft_strdel(line);
		get_next_line(0, line);
		this_is_comment_or_command(line);
		if (!create_room(*line, room == 1 ? &g_lem_in.start : &g_lem_in.end))
			return (0);
	}
	else
		return (0);
	return (1);
}

int 	find_room(char *line)
{
	t_room	*head;

	line ? ft_strdel(&line) : 0;
	while (get_next_line(0, &line))
	{
		this_is_comment_or_command(&line);
		if (ft_isprint(*line) && *line != 'L' && *line != '#' && *line != 32)
		{
			if (!create_room(line, &head))
				return (0);
		}
		else if (*line == '#' && *(line + 1) == '#')
		{
			if (!create_start_or_end(&line))
				return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}