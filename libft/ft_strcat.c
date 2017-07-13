/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:02:12 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/02 12:27:43 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int count;

	i = (int)ft_strlen(dst);
	count = 0;
	while (src[count])
	{
		dst[i] = src[count];
		count++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
