/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:20:14 by yzakharc          #+#    #+#             */
/*   Updated: 2016/11/30 17:45:28 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *dest;

	dest = (unsigned char *)s;
	while (n--)
		if (*dest++ == (unsigned char)c)
			return (dest - 1);
	return (NULL);
}
