/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:15:20 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/12 15:15:21 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int 	valid_line_room(char *line)
{
	size_t	len_line;
	size_t	len_room;
	int 	len_x;
	int 	len_y;

	len_line = ft_strlen(line);
	len_room = ft_strlen(g_lem_in.room);
	len_x = len_value(g_lem_in.x_room);
	len_y = len_value(g_lem_in.y_room);
	if (len_line > len_room + len_x + len_y + 2)
		return (0);
	return (1);
}

int		this_is_comment_or_command(char **line)
{
	while (**line == '#' && *(*line + 1) != '#')
	{
		write_map(*line, 4);
		ft_strdel(line);
		get_next_line(g_fd, line);
	}
	while (**line == '#' && *(*line + 1) == '#')
	{
		if (!ft_strcmp(*line + 2, "start") || (!ft_strcmp(*line + 2, "end")))
		{
			return (g_lem_in.start_cnt == 1 && g_lem_in.end_cnt == 1 ? 0 : 1);
		}
		else
		{
			write_map(*line, 1);
			ft_strdel(line);
			if (!get_next_line(g_fd, line))
				return (1);
		}
	}
	return (1);
}

int 	num_ants(char *line)
{
	intmax_t	ant;
	int 		len;

	if (!this_is_comment_or_command(&line))
		return (0);
	if (!ft_isdigit(*line))
		return (0);
	else
	{
		ant = ft_atoi_pf(line);
		len = len_value(ant);
		if (ant > 2147483647 || ft_isprint(line[len]))
			return (0);
		g_lem_in.ant = ft_atoi(line);
		write_map(line, 2);
	}
	return (1);
}