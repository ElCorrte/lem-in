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
	int 			this_is;
	int 			i_was_here;
	int 			distance;
	struct s_join	*join;
	struct s_room	*next;
}					t_room;

typedef struct		s_join
{
	t_room			*room;
	struct s_join	*next;
}					t_join;

typedef struct		s_link
{
	char 			*room_1;
	char 			*room_2;
	struct s_link	*next;
}					t_link;

typedef struct 		s_print
{
	char 			*print_line;
	int 			color;
	struct s_print	*next;
}					t_print;

typedef struct		s_path
{
	char 			*name;
	int 			ant_came;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_lem
{
	int 			ant;
	int 			cnt;
	char 			*room;
	int 			x_room;
	int 			y_room;
	int				start_cnt;
	int				end_cnt;
	int 			room_completed;
	int 			new_room;
	int 			len_room;
}					t_lem;

t_lem				g_lem_in;

t_print				*g_head;
t_print				*g_end;

t_path				*g_start_path;
t_path				*g_end_path;

int 				find_room(char **line, t_room **head);
int					valid_line_room(char *line);
int					maybe_link(char *line);
int					find_link(char **line, t_link **head, t_room *head_room);
int 				num_ants(char **line);
int					this_is_comment_or_command(char **line);
int					write_name_room_or_link(char *line, int *cnt, int c,\
					char **room);

int					build_links(t_room **room, t_link *link);

int 				find_the_shortest_path(t_room *room);
void				write_the_shortest_path(t_room *room);

void				start_ants(void);

void				write_map(char *line, int color);
void				clear_struct(void);
int					len_path(void);

#endif
