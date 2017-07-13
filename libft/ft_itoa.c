/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:42:01 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 16:28:45 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*new;
	int		i;

	len = ft_nbri(n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (n > 0)
		i = -1;
	else
		i = 0;
	if (n == 0)
	{
		new[0] = 48;
		return (new);
	}
	ft_nbrstr(n, new, i);
	ft_strrev(new);
	return (new);
}
