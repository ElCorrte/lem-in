/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:49:39 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/05 14:01:22 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	count;
	int		i;

	i = 0;
	if (!(s) || !(f))
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	count = 0;
	while (s[count])
	{
		new[count] = f(i++, s[count]);
		count++;
	}
	return (new);
}
