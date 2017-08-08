/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 19:23:26 by yzakharc          #+#    #+#             */
/*   Updated: 2017/08/04 19:49:21 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lem_in.h"

int		error_mes(void)
{
	ft_printf(RED"ERROR\n"RESET);
	return (0);
}

void	write_map(char *line, int color)
{
	t_print *tmp;

	tmp = (t_print *)malloc(sizeof(t_print));
	tmp->print_line = ft_strdup(line);
	tmp->color = color;
	tmp->next = NULL;
	if (g_head == NULL)
	{
		g_head = tmp;
		g_end = tmp;
		return ;
	}
	g_end->next = tmp;
	g_end = tmp;
}

void	print_map(void)
{
	t_print	*tmp;

	tmp = g_head;
	while (tmp)
	{
		tmp->color == 1 ? ft_printf(RED"%s\n"RESET, tmp->print_line) : 0;
		tmp->color == 2 ? ft_printf(YELLOW"%s\n"RESET, tmp->print_line) : 0;
		tmp->color == 3 ? ft_printf(BLUE"%s\n"RESET, tmp->print_line) : 0;
		tmp->color == 4 ? ft_printf(GREEN"%s\n"RESET, tmp->print_line) : 0;
		tmp = tmp->next;
	}
}

int		valid_map(t_room **head_room, t_link **head_link)
{
	char	*line;

	line = NULL;
	g_fd = open("test", O_RDONLY);
	//g_fd = 0;
	while (get_next_line(g_fd, &line))
	{
		if (!g_lem_in.ant)
		{
			if (!num_ants(&line))
				return (0);
		}
		if (!g_lem_in.room_completed && !find_room(&line, head_room))
			return (0);
		if (g_lem_in.start_cnt != 1 || g_lem_in.end_cnt != 1)
			return (0);
		if (!find_link(&line, head_link, *head_room))
			return (0);
		line ? ft_strdel(&line) : 0;
	}
	return (1);
}

int		main(void)
{
	t_room	*head_room;
	t_link	*head_link;

	head_room = NULL;
	head_link = NULL;
	clear_struct();
	if (!valid_map(&head_room, &head_link))
		return (error_mes());
	build_links(&head_room, head_link);
	find_the_shortest_path(head_room);
	write_the_shortest_path(head_room);
	print_map();
	start_ants(g_lem_in.ant);
	return (0);
}
