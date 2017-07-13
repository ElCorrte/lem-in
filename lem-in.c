/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:57:09 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/06 17:57:10 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int 	error_mes(void)
{
	ft_printf("ERROR\n");
	return (0);
}

void	write_map(char *line)
{
	t_print *tmp;

	tmp = (t_print *)malloc(sizeof(t_print));
	tmp->print_line = ft_strdup(line);
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
		ft_printf("%s\n", tmp->print_line);
		tmp = tmp->next;
	}
}

int		valid_map(void)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!g_lem_in.ant)
			if (!num_ants(line))
				return (0);
		else if (!find_room(line))
			return (0);
		ft_strdel(&line);
	}
	print_map();
	return (1);
}

int 	main(void)
{
	if (!valid_map())
		return (error_mes());
	return (0);
}