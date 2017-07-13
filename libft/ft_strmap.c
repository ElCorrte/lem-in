/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:37:36 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/05 14:00:49 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	count;

	if (!(s) || !(f))
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	count = 0;
	while (s[count])
	{
		new[count] = f(s[count]);
		count++;
	}
	return (new);
}
