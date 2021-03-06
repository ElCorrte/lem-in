/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:17:22 by yzakharc          #+#    #+#             */
/*   Updated: 2017/08/04 18:43:23 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_struct(void)
{
	g_lem_in.room = NULL;
	g_lem_in.ant = 0;
	g_lem_in.cnt = 0;
	g_lem_in.x_room = 0;
	g_lem_in.y_room = 0;
	g_lem_in.start_cnt = 0;
	g_lem_in.end_cnt = 0;
	g_lem_in.room_completed = 0;
	g_lem_in.new_room = 0;
}
