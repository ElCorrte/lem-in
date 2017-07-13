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


int 				g_fd;

typedef struct		s_room
{
	char			*name;
	int 			x;
	int 			y;
	int 			func_room;
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
	char 			*room;
	int 			x_room;
	int 			y_room;
	int				start_cnt;
	int				end_cnt;
}					t_lem;

t_lem				g_lem_in;

t_print				*g_head;
t_print				*g_end;

int 				find_room(char *line);
int 				num_ants(char *line);
void				this_is_comment_or_command(char **line);
void				write_map(char *line);

#endif
