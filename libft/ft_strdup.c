/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:53:25 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/02 12:28:22 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		tot;
	int		count;

	count = ft_strlen(str);
	tot = 0;
	if (!(dest = (char*)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	while (str[tot])
	{
		dest[tot] = str[tot];
		tot++;
	}
	dest[tot] = '\0';
	return (dest);
}
