/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:26:24 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/02 16:29:40 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	len;

	len = size;
	if (!(s = (char *)malloc((size + 1) * sizeof(*s))))
		return (NULL);
	while (size--)
		*s++ = '\0';
	*s = '\0';
	return (s - len);
}
