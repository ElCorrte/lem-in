/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:06 by yzakharc          #+#    #+#             */
/*   Updated: 2017/07/04 20:17:50 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_n(va_list *fm, t_pf *pf)
{
	int *n;

	n = va_arg(*fm, void *);
	*n = pf->print_smb;
	return (0);
}

int		ft_plus_space(t_pf *pf)
{
	char	*pl_sp;
	char	*tmp;

	if (pf->zero == 1 && pf->width > 0 && *pf->str != '-' && pf->plus == 1)
		return (zero_space_plus(pf));
	if (pf->zero == 1 && pf->width > 0 && *pf->str != '-' && pf->space == 1)
		return (zero_space_plus(pf));
	pl_sp = ft_strnew(1);
	if (pf->spcr == 'i' || pf->spcr == 'd' || pf->spcr == 'D')
	{
		if ((pf->plus == 1 && *pf->str != '-') ||
			(pf->space == 1 && !pf->plus && *pf->str != '-'))
		{
			pl_sp[0] = pf->plus && !pf->space ? '+' : 0;
			pl_sp[0] = pf->space && !pf->plus ? ' ' : 0;
			tmp = pf->str;
			pf->str = ft_strjoin(pl_sp, pf->str);
			ft_strdel(&tmp);
		}
	}
	ft_strdel(&pl_sp);
	return (0);
}

void	print_dash(t_pf *pf)
{
	pf->sharp == 1 || pf->spcr == 'p' ? ft_sharp(pf) : 0;
	if (pf->str)
		pf->fd ? ft_putstr_fd(pf->str, pf->fd) : putstr_pf(pf->str, pf);
	(pf->width > pf->dot) ? print_width(len_for_width(pf), pf) : 0;
	pf->str_clean == 1 ? ft_strdel(&pf->str) : 0;
	pf->dash_true = 1;
}

void	use_flag(t_pf *pf)
{
	if (pf->spcr != 'c')
		pf->dot != -1 && pf->dot ? create_dot(pf->str, pf->dot, pf) : 0;
	(pf->plus == 1 || pf->space == 1) ? ft_plus_space(pf) : 0;
	pf->dash == 1 ? print_dash(pf) : 0;
	if (pf->width && pf->width > pf->dot && pf->width > (int)ft_strlen(pf->str))
		print_width(len_for_width(pf), pf);
	(!pf->sharp_true && (pf->sharp == 1 || pf->spcr == 'p')) ? ft_sharp(pf) : 0;
	if (!pf->dash_true)
	{
		if (pf->plus_one)
			pf->fd ? ft_putstr_fd(pf->str + 1, pf->fd) :
				putstr_pf(pf->str + 1, pf);
		else
			pf->fd ? ft_putstr_fd(pf->str, pf->fd) : putstr_pf(pf->str, pf);
		pf->str_clean == 1 ? ft_strdel(&pf->str) : 0;
	}
}

int		ft_check_sp(char sp, va_list *fm, t_pf *pf)
{
	if (sp == 'w')
		return (0);
	pf->spcr = sp;
	pf->spcr == 's' && pf->l == 1 ? pf->spcr = 'S' : 0;
	pf->spcr == 'c' && pf->l == 1 ? pf->spcr = 'C' : 0;
	if (pf->spcr == 'n')
		return (print_n(fm, pf));
	(sp == 'i' || sp == 'd' || sp == 'D') ? ft_mod_d_i(fm, pf) : 0;
	pf->spcr == 'S' ? print_wchar(fm, pf) : 0;
	if (pf->spcr == 's' && pf->dot != -1)
		if (!(pf->str = va_arg(*fm, char *)))
			pf->str = "(null)";
	pf->spcr == 's' && pf->dot == -1 ? pf->str = strnew_pf(0, pf) : 0;
	pf->spcr == 'c' ? print_c(fm, pf) : 0;
	pf->spcr == 'C' ? print_c_big(fm, pf) : 0;
	sp == 'b' ? ft_mod_other(fm, pf, 2, 0) : 0;
	sp == 'p' ? ft_mod_other(fm, pf, 16, 39) : 0;
	(sp == 'u' || sp == 'U') ? ft_mod_other(fm, pf, 10, 0) : 0;
	(sp == 'o' || sp == 'O') ? ft_mod_other(fm, pf, 8, 0) : 0;
	sp == 'x' ? ft_mod_other(fm, pf, 16, 39) : 0;
	sp == 'X' ? ft_mod_other(fm, pf, 16, 7) : 0;
	remove_unnecessary(pf);
	pf->dot == -1 && pf->width > 0 && pf->spcr != 'd' ? pf->dot = 0 : 0;
	use_flag(pf);
	return (0);
}
