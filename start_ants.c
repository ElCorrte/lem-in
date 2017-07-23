/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:43:52 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/23 17:22:25 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_result(void)
{
	t_path	*tmp;
	int 	cnt;

	cnt = g_start_path->ant_came == 0 ? 1 : g_start_path->ant_came;
	tmp = g_start_path;
	while (tmp)
	{
		if (tmp->ant_came > 0 && !ft_strequ(tmp->name, g_end_path->name))
		{
			ft_printf("L%i-%s ", cnt, tmp->name);
			cnt++;
		}
		tmp = tmp->next;
	}
}

int 	len_path(void)
{
	t_path	*tmp;
	int 	cnt;

	cnt = 0;
	tmp = g_start_path;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

void	value_tmp(int *tmp)
{
	if (*tmp == 0)
		*tmp = g_lem_in.cnt;
	else if (*tmp > 0)
		g_lem_in.cnt = *tmp;
	if (*tmp >= g_lem_in.len_room || g_lem_in.cnt >= g_lem_in.len_room)
	{
		g_lem_in.len_room--;
		*tmp = g_lem_in.len_room;
	}
}

void	start_ants(void)
{
	t_path	*tmp;
	int 	tmp_cnt;

	tmp = g_start_path;
	tmp_cnt = 1;
	while (g_start_path->ant_came != g_lem_in.ant)
	{
		tmp_cnt != 1 ? ft_printf("\n") : 0;
		value_tmp(&tmp_cnt);
		while (tmp_cnt)
		{
			if (tmp->next->ant_came == g_end_path->ant_came ||
					tmp->next->ant_came == 1)
			{
				tmp->next->ant_came--;
				tmp->ant_came++;
				tmp_cnt--;
				g_lem_in.cnt++;
			}
			tmp = tmp->next;
		}
		print_result();
		tmp = g_start_path;
	}
}
