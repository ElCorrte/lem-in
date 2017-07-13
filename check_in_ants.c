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

void	this_is_comment_or_command(char **line)
{
	while (**line == '#' && *(*line + 1) != '#')
	{
		ft_strdel(line);
		get_next_line(0, line);
	}
	while (**line == '#' && *(*line + 1) == '#')
	{
		if (!ft_strcmp(*line + 2, "start") || (!ft_strcmp(*line + 2, "end")))
			return ;
		else
		{
			ft_strdel(line);
			get_next_line(0, line);
		}
	}
}

int 	num_ants(char *line)
{
	intmax_t len;

	this_is_comment_or_command(&line);
	if (!ft_isdigit(*line))
		return (0);
	else
	{
		len = ft_atoi_pf(line);
		if (len > 2147483647)
			return (0);
		g_lem_in.ant = ft_atoi(line);
		write_map(line);
	}
	return (1);
}