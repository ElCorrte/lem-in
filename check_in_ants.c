/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:15:20 by yzakharc          #+#    #+#             */
/*   Updated: 2017/08/07 16:49:35 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_line_room(char *line)
{
	size_t	len_line;
	size_t	len_room;
	int		len_x;
	int		len_y;

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
	if (*line == NULL)
		return (1);
	while (**line == '#' && (!ft_strequ(*line + 2, "end") &&\
				!ft_strequ(*line + 2, "start")))
	{
		write_map(*line, 4);
		ft_strdel(line);
		if (!get_next_line(g_fd, line))
			return (1);
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

int		num_ants(char **line)
{
	intmax_t	ant;
	int			len_num;
	int			len_line;

	if (!this_is_comment_or_command(line))
		return (0);
	if (!ft_isdigit(**line))
		return (0);
	else
	{
		ant = ft_atoi_pf(*line);
		len_num = len_value(ant);
		len_line = (int)ft_strlen(*line);
		if (ant > 2147483647 || ant == 0 || len_line != len_num)
			return (0);
		g_lem_in.ant = ft_atoi(*line);
		write_map(*line, 2);
	}
	return (1);
}
