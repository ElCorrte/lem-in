/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:56:19 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/08 15:41:02 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*dst;

	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		dst->content = NULL;
		dst->content_size = 0;
	}
	else
	{
		if (!(dst->content = (void *)malloc(sizeof(content) * (content_size))))
			return (NULL);
		ft_memcpy(dst->content, content, content_size);
		dst->content_size = content_size;
	}
	dst->next = NULL;
	return (dst);
}
