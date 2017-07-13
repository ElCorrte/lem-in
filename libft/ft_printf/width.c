/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:32:47 by yzakharc          #+#    #+#             */
/*   Updated: 2017/06/08 15:16:54 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_for_width(t_pf *pf)
{
	int	i;

	i = 0;
	if (pf->str && pf->spcr != 'c')
		i = (int)ft_strlen(pf->str);
	else if (pf->spcr == 'c')
		i = 1;
	return (i);
}

int		check_width(t_pf *pf, const char **str, va_list *fm)
{
	if (**str == '*')
	{
		pf->width = va_arg(*fm, int);
		if (pf->width < 0)
		{
			pf->dash = 1;
			pf->width *= -1;
		}
		(*str)++;
		return (0);
	}
	pf->width = ft_atoi_pf(*str);
	pf->len_width = len_value(pf->width);
	*str += pf->len_width;
	return (0);
}

void	print_width_rev1(t_pf *pf)
{
	while (pf->new_width != 0)
	{
		if (!pf->dash)
		{
			if (pf->zero && !pf->dot)
				pf->fd ? ft_putchar_fd('0', pf->fd) : putchar_pf('0', pf);
			else
				pf->fd ? ft_putchar_fd(' ', pf->fd) : putchar_pf(' ', pf);
		}
		else
			pf->fd ? ft_putchar_fd(' ', pf->fd) : putchar_pf(' ', pf);
		pf->new_width--;
	}
}

void	print_width(int minus, t_pf *pf)
{
	pf->new_width = pf->width;
	pf->width = 0;
	pf->new_width -= minus;
	if (pf->sharp || pf->spcr == 'p')
	{
		pf->zero && !pf->sharp_true ? ft_sharp(pf) : 0;
		(pf->spcr == 'o' || pf->spcr == 'O') ? pf->new_width -= 1 : 0;
		if (pf->spcr == 'x' || pf->spcr == 'X' || pf->spcr == 'p')
			pf->new_width -= 2;
	}
	if (pf->str && *pf->str == '-' && !pf->dash && pf->zero != 0)
	{
		pf->fd ? ft_putchar_fd('-', pf->fd) : putchar_pf('-', pf);
		pf->plus_one = 1;
	}
	pf->new_width > 0 ? print_width_rev1(pf) : 0;
}
