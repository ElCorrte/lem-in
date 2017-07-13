/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:31:20 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/10 20:39:58 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		skip_zero(const char **fl)
{
	while (**fl == '0' && **fl)
		(*fl)++;
	return (0);
}

int		skip_hh_ll(const char **fl, t_pf *pf)
{
	if (**fl == 'h' && *(*fl + 1) != 'h')
	{
		pf->cnt++;
		if (pf->cnt % 2 == 0)
		{
			pf->hh = 1;
			pf->h = 0;
		}
		else
			pf->h = 1;
		(*fl)++;
	}
	if (**fl == 'h' && *(*fl + 1) == 'h')
	{
		pf->hh = 1;
		(*fl) += 2;
	}
	if (**fl == 'l' && *(*fl + 1) == 'l')
	{
		pf->ll = 1;
		(*fl) += 2;
	}
	return (0);
}

int		ft_check_fl(const char **fl, t_pf *pf, va_list *fm)
{
	while (ft_strchr(pf->f_l, **fl) && **fl)
	{
		if (**fl == '0' && (pf->zero = 1))
			return (skip_zero(fl));
		**fl == '#' ? pf->sharp = 1 : 0;
		**fl == '-' ? pf->dash = 1 : 0;
		**fl == '+' ? pf->plus = 1 : 0;
		**fl == ' ' ? pf->space = 1 : 0;
		if (**fl == '.')
			return (check_dot(pf, fl, fm));
		if (**fl == 'h' && *(*fl + 1) != 'h')
			return (skip_hh_ll(fl, pf));
		if (**fl == 'h' && *(*fl + 1) == 'h')
			return (skip_hh_ll(fl, pf));
		**fl == 'l' && *(*fl + 1) != 'l' ? pf->l = 1 : 0;
		if (**fl == 'l' && *(*fl + 1) == 'l')
			return (skip_hh_ll(fl, pf));
		**fl == 'j' ? pf->j = 1 : 0;
		**fl == 'z' ? pf->z = 1 : 0;
		if (ft_isdigit(**fl) || **fl == '*')
			return (check_width(pf, fl, fm));
		(*fl)++;
	}
	return (0);
}

int		ft_check_form(const char *form, va_list *fm, t_pf *pf)
{
	while (*form)
	{
		clean_all(pf);
		while (*form != '%' && *form)
		{
			pf->fd ? ft_putchar_fd(*form, pf->fd) : putchar_pf(*form, pf);
			form++;
		}
		*form ? form++ : 0;
		while (ft_strchr(pf->f_l, *form) && *form)
			ft_check_fl(&form, pf, fm);
		*form == 'U' || *form == 'D' || *form == 'O' ? pf->l = 1 : 0;
		ft_trunk(pf);
		if (ft_strchr(pf->s_p, *form) && *form)
		{
			if (*form == 'w')
				pf->fd = va_arg(*fm, int);
			ft_check_sp(*form, fm, pf);
		}
		else
			*form ? ft_check_smb(*form, pf) : 0;
		*form ? form++ : 0;
	}
	return (pf->print_smb);
}

int		ft_printf(const char *format, ...)
{
	va_list	fm;
	int		how_mach;
	t_pf	pf;

	pf.s_p = "wsSpdDioOuUxXcCnb";
	pf.f_l = "#0-+  .hljz123456789*";
	pf.print_smb = 0;
	va_start(fm, format);
	pf.fd = 0;
	how_mach = ft_check_form(format, &fm, &pf);
	pf.str_clean == 1 ? ft_strdel(&pf.str) : 0;
	clean_all(&pf);
	pf.fd = 0;
	va_end(fm);
	return (how_mach);
}
