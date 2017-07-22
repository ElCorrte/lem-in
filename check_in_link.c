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

int 	valid_link(char *room1, char *room2, t_room *head_room)
{
	t_room	*tmp;
	int 	i;

	i = 0;
	tmp = head_room;
	while (tmp)
	{
		(ft_strequ(tmp->name, room1) || ft_strequ(tmp->name, room2)) ? i++ : 0;
		tmp = tmp->next;
	}
	return (i == 2 ? 1 : 0);
}

void	write_links_in_list(char *room1, char *room2, t_link **head_link)
{
	t_link *tmp;

	tmp = (t_link *)malloc(sizeof(t_link));
	tmp->room_1 = ft_strdup(room1);
	tmp->room_2 = ft_strdup(room2);
	tmp->next = (*head_link);
	(*head_link) = tmp;
}

int		create_link(char *line, t_room *head_room, t_link **head_link)
{
	char	*room_1;
	char	*room_2;
	int		cnt;
	size_t	len;

	cnt = 0;
	len = ft_strlen(line);
	room_1 = NULL;
	if (!write_name_room_or_link(line, &cnt, '-', &room_1))
		return (0);
	cnt += 1;
	room_2 = ft_strnew(len - cnt);
	ft_strncpy(room_2, line + cnt, (size_t)len - cnt);
	if (!valid_link(room_1, room_2, head_room))
		return (0);
	write_links_in_list(room_1, room_2, head_link);
	write_map(line, 2);
	ft_strdel(&room_1);
	ft_strdel(&room_2);
	return (1);
}

int		find_link(char **line, t_link **head_link, t_room *head_room)
{
	if (!this_is_comment_or_command(line))
		return (0);
	if (!*line)
		return (1);
	if (ft_isprint(**line) && **line != 32 && **line != 'L' && **line != '#')
	{
		if (!ft_strchr(*line, '-'))
			return (0);
		if (!create_link(*line, head_room, head_link))
			return (0);
	}
	return (1);
}