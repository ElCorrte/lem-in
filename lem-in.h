/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:57:16 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/06 17:57:21 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"


typedef struct		s_room
{
	char			*name;
	int 			x;
	int 			y;
	struct s_room	*next;
}					t_room;

typedef struct 		s_print
{
	char 			*print_line;
	struct s_print	*next;
}					t_print;

typedef struct		s_lem
{
	int 			ant;
	t_room			*start;
	t_room			*end;
}					t_lem;

t_lem				g_lem_in;

t_print				*g_head;
t_print				*g_end;

int 				find_room(char *line);
int 				num_ants(char *line);
void				this_is_comment_or_command(char **line);
void				write_map(char *line);

#endif
