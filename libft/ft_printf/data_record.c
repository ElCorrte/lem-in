/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:50:13 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/10 17:41:44 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_mod(t_pf *pf)
{
	if (!pf->hh && !pf->h && !pf->l && !pf->ll && !pf->j && !pf->z)
		pf->no_mod = 1;
}

void	ft_check_smb(int s, t_pf *pf)
{
	int *i;
	int tmp;

	pf->spcr = 'c';
	tmp = 0;
	i = &s;
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
	use_flag(pf);
}

void	clean_all(t_pf *pf)
{
	pf->str = NULL;
	pf->spcr = 1;
	pf->sharp_true = 0;
	pf->sharp = 0;
	pf->zero = 0;
	pf->dash = 0;
	pf->dash_true = 0;
	pf->plus = 0;
	pf->space = 0;
	pf->width = 0;
	pf->new_width = 0;
	pf->len_width = 0;
	pf->dot = 0;
	pf->len_dot = 0;
	pf->h = 0;
	pf->hh = 0;
	pf->l = 0;
	pf->ll = 0;
	pf->j = 0;
	pf->z = 0;
	pf->no_mod = 0;
	pf->str_clean = 0;
	pf->plus_one = 0;
	pf->cnt = 0;
}

void	ft_mod_d_i(va_list *fm, t_pf *pf)
{
	char *c;

	pf->str = strnew_pf(0, pf);
	c = pf->str;
	no_mod(pf);
	pf->hh == 1 ? ft_itoa_dec((signed char)va_arg(*fm, int), pf) : 0;
	pf->h == 1 ? ft_itoa_dec((short)va_arg(*fm, int), pf) : 0;
	pf->l == 1 ? ft_itoa_dec(va_arg(*fm, long), pf) : 0;
	pf->ll == 1 ? ft_itoa_dec(va_arg(*fm, long long), pf) : 0;
	pf->j == 1 ? ft_itoa_dec(va_arg(*fm, intmax_t), pf) : 0;
	pf->z == 1 ? ft_itoa_dec(va_arg(*fm, size_t), pf) : 0;
	pf->no_mod && pf->spcr == 'D' ? ft_itoa_dec(va_arg(*fm, long), pf) : 0;
	!*pf->str ? ft_itoa_dec(va_arg(*fm, int), pf) : 0;
	ft_strdel(&c);
	pf->value = ft_atoi_pf(pf->str);
}

void	ft_mod_other(va_list *fm, t_pf *pf, int key, int x)
{
	char *c;

	pf->str = strnew_pf(0, pf);
	c = pf->str;
	no_mod(pf);
	pf->hh == 1 ? itoa_hex_oct((unsigned char)va_arg(*fm, int), pf, key, x) : 0;
	pf->h == 1 ? itoa_hex_oct((unsigned short)va_arg(*fm, int), pf, key, x) : 0;
	pf->l == 1 ? itoa_hex_oct(va_arg(*fm, unsigned long), pf, key, x) : 0;
	pf->ll == 1 ? itoa_hex_oct(va_arg(*fm, unsigned long long), pf, key, x) : 0;
	pf->j == 1 ? itoa_hex_oct(va_arg(*fm, uintmax_t), pf, key, x) : 0;
	pf->z == 1 ? itoa_hex_oct(va_arg(*fm, size_t), pf, key, x) : 0;
	if (pf->no_mod && (pf->spcr == 'p' || pf->spcr == 'U' || pf->spcr == 'O'))
		itoa_hex_oct(va_arg(*fm, unsigned long), pf, key, x);
	!*pf->str ? itoa_hex_oct(va_arg(*fm, unsigned int), pf, key, x) : 0;
	ft_strdel(&c);
	pf->value = ft_atoi_pf(pf->str);
}
