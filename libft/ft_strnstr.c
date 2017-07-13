/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:10:08 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/05 11:39:51 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	c;

	c = ft_strlen(little);
	len++;
	while (*big++ && len-- > 0 && (c <= len))
	{
		if ((ft_strncmp((big - 1), little, c) == 0) || c == 0)
			return ((char *)(big - 1));
	}
	return (NULL);
}
