/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:48:55 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/04 15:45:49 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_value(intmax_t value)
{
	int i;

	i = 0;
	value < 0 ? i++ : 0;
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

void	ft_itoa_dec(intmax_t value, t_pf *pf)
{
	int			i;
	intmax_t	c;

	i = len_value(value);
	pf->str = strnew_pf((size_t)i, pf);
	value == 0 ? pf->str[0] = '0' : 0;
	value < 0 ? pf->str[0] = '-' : 0;
	while (value != 0)
	{
		c = value % 10;
		if (c < 0)
			c = -c;
		pf->str[i-- - 1] = (char)(c + 48);
		value /= 10;
	}
}

int		len_value_hex_oct(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

void	itoa_hex_oct(uintmax_t value, t_pf *pf, int base, int x)
{
	int			i;
	uintmax_t	c;

	i = len_value_hex_oct(value, base);
	pf->str = strnew_pf((size_t)i, pf);
	value == 0 ? pf->str[0] = '0' : 0;
	while (value != 0)
	{
		c = value % base;
		c > 9 ? c += x : 0;
		pf->str[i-- - 1] = (char)(c + 48);
		value /= base;
	}
}
