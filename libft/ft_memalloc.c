/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:15:57 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/02 14:42:06 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;
	size_t			len;

	len = size;
	if (!(s = (void *)malloc(size * sizeof(*s))))
		return (NULL);
	while (size--)
		*s++ = 0;
	return (s - len);
}
