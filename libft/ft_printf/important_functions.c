/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   important_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:39:04 by yzakharc          #+#    #+#             */
/*   Updated: 2017/06/08 15:18:03 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_space_plus(t_pf *pf)
{
	if (pf->zero == 1 && pf->width > 0 && *pf->str != '-' && pf->plus == 1)
	{
		pf->fd ? ft_putchar_fd('+', pf->fd) : putchar_pf('+', pf);
		pf->width--;
		return (0);
	}
	if (pf->zero == 1 && pf->width > 0 && *pf->str != '-' && pf->space == 1)
	{
		pf->fd ? ft_putchar_fd(' ', pf->fd) : putchar_pf(' ', pf);
		pf->width--;
		return (0);
	}
	return (0);
}

void	ft_trunk_1(t_pf *pf)
{
	if (pf->ll == 1)
	{
		pf->l = 0;
		pf->h = 0;
		pf->hh = 0;
	}
	if (pf->l == 1)
	{
		pf->h = 0;
		pf->hh = 0;
	}
	if (pf->h == 1)
		pf->hh = 0;
}

void	ft_trunk(t_pf *pf)
{
	if (pf->z == 1)
	{
		pf->j = 0;
		pf->ll = 0;
		pf->l = 0;
		pf->h = 0;
		pf->hh = 0;
	}
	if (pf->j == 1)
	{
		pf->ll = 0;
		pf->l = 0;
		pf->h = 0;
		pf->hh = 0;
	}
	ft_trunk_1(pf);
}

char	*strnew_pf(size_t size, t_pf *pf)
{
	char	*s;
	size_t	len;

	len = size;
	if (!(s = (char *)malloc((size + 1) * sizeof(*s))))
		return (NULL);
	while (size--)
		*s++ = '\0';
	*s = '\0';
	pf->str_clean = 1;
	return (s - len);
}
