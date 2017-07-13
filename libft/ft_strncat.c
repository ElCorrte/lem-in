/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:19:49 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/05 11:39:19 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(dst);
	count = 0;
	while (src[count] && count < n)
	{
		dst[i] = src[count];
		count++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
