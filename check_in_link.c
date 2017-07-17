/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 13:02:05 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/14 13:02:06 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int 	maybe_link(char *line)
{
	int cnt;
	int dash;

	cnt = 0;
	dash = 0;
	if (ft_strchr(line, 32))
		return (0);
	while (line[cnt])
	{
		line[cnt] == '-' ? dash++ : 0;
		cnt++;
	}
	if (dash > 1)
		return (0);
	else if (dash == 1)
		return (1);
	return (0);
}

int		create_link(char *line, t_link **head)
{
	char	*room_1;
	char	*room_2;
	int		cnt;
	size_t	len;

	cnt = 0;
	len = ft_strlen(line);
	if (!write_name_room_or_link(line, &cnt, '-', &room_1))
		return (0);
	cnt += 1;
	room_2 = ft_strnew(len - cnt);
	ft_strncpy(room_2, line + cnt, (size_t)cnt);
	return (1);
}

int		find_link(char *line, t_link *head)
{
	this_is_comment_or_command(&line);
	if (ft_isprint(*line) && *line != 32 && *line != 'L' && *line != '#')
	{
		if (!create_link(line, &head))
			return (0);
	}
	return (1);
}