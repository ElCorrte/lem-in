/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:10:08 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/01 16:17:33 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	while (*big++ || ft_strlen(little) == 0)
		if (ft_strncmp((big - 1), little, ft_strlen((char *)little)) == 0)
			return ((char *)big - 1);
	return (NULL);
}
