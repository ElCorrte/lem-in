/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:30:13 by yzakharc          #+#    #+#             */
/*   Updated: 2017/03/03 10:30:45 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

# define BUFF_SIZE 1

typedef struct		s_line
{
	char			*str;
	int				fd;
	struct s_line	*next;

}					t_line;

int					get_next_line(const int fd, char **line);

#endif
