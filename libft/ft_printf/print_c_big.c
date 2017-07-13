/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 21:25:19 by yzakharc          #+#    #+#             */
/*   Updated: 2017/06/08 15:16:23 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_c(t_pf *pf)
{
	pf->dot = 0;
	pf->plus = 0;
	pf->sharp = 0;
	pf->value = ft_atoi_pf(pf->str);
	pf->spcr = 'c';
}

void	print_c(va_list *fm, t_pf *pf)
{
	int c;

	c = va_arg(*fm, int);
	pf->str = strnew_pf(1, pf);
	pf->str = add_to_string(pf->str, (char)c);
	clear_c(pf);
}

void	print_c_big(va_list *fm, t_pf *pf)
{
	int c;
	int *i;
	int tmp;

	c = va_arg(*fm, int);
	i = &c;
	pf->str = strnew_pf(1, pf);
	if (*i < 128)
	{
		tmp = *i;
		pf->str = add_to_string(pf->str, (char)tmp);
	}
	if (*i > 255 && *i < 2048)
	{
		tmp = *i >> 6;
		tmp |= 192;
		pf->str = add_to_string(pf->str, (char)tmp);
		tmp = *i;
		tmp &= 63;
		tmp |= 128;
		pf->str = add_to_string(pf->str, (char)tmp);
	}
	*i >= 2048 && *i < 65536 ? print_three_bytes(0, i, pf) : 0;
	*i >= 65546 && *i < 2097152 ? print_four_bytes(0, i, pf) : 0;
	clear_c(pf);
}
