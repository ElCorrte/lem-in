/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:50:38 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/04 20:10:00 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		remove_unnecessary(t_pf *pf)
{
	int len;

	pf->space == 1 && pf->plus == 1 ? pf->space = 0 : 0;
	if (pf->dot == -1 && pf->value == 0)
		if (pf->sharp != 1 || (pf->sharp == 1 && pf->spcr == 'x'))
			*pf->str = '\0';
	if (pf->spcr == 'x' || pf->spcr == 'X' || pf->spcr == 'u' ||\
			pf->spcr == 'U' || pf->spcr == 'o' || pf->spcr == 'O')
	{
		pf->space = 0;
		pf->plus = 0;
		pf->value == 0 ? pf->sharp = 0 : 0;
	}
	if (pf->spcr == 'o' || pf->spcr == 'O')
	{
		len = len_value(pf->value);
		len < pf->dot ? pf->sharp = 0 : 0;
	}
	if (pf->spcr != 'x' && pf->spcr != 'X' && pf->spcr != 'p' &&\
			pf->spcr != 'o' && pf->spcr != 'O')
		pf->sharp = 0;
}

void		putchar_pf(char c, t_pf *pf)
{
	write(1, &c, 1);
	pf->print_smb++;
}

void		putstr_pf(char const *s, t_pf *pf)
{
	if (s == NULL)
		return ;
	while (*s++)
		putchar_pf(*(s - 1), pf);
	pf->spcr == 'c' && *pf->str == 0 ? putchar_pf(0, pf) : 0;
}

void		ft_sharp(t_pf *pf)
{
	pf->spcr == 'o' && pf->value > 0 ? pf->dot = 0 : 0;
	if ((*pf->str != '0' && pf->dot != -1) || pf->spcr == 'p' ||\
			pf->spcr == 'o' || pf->spcr == 'O' || pf->spcr == 'x'\
			|| pf->spcr == 'X')
	{
		(pf->spcr == 'o' || pf->spcr == 'O') ? putchar_pf('0', pf) : 0;
		pf->spcr == 'x' || pf->spcr == 'p' ? putstr_pf("0x", pf) : 0;
		pf->spcr == 'X' ? putstr_pf("0X", pf) : 0;
		pf->sharp_true = 1;
	}
	else
		return ;
}

intmax_t	ft_atoi_pf(const char *str)
{
	intmax_t	b;
	int			d;

	b = 0;
	while (ft_isspace(*str) == 1)
		str++;
	d = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		b = b * 10 + (*str - '0');
		str++;
	}
	return (b * d);
}
