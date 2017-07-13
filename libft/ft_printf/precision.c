/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:27:48 by yzakharc          #+#    #+#             */
/*   Updated: 2017/06/07 19:51:20 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_int(t_pf *pf)
{
	int		i;
	char	*c;

	pf->is_int = "pdDioOuUxXb";
	c = ft_strchr(pf->is_int, pf->spcr);
	i = !c ? 0 : 1;
	return (i);
}

int		check_dot(t_pf *pf, const char **str, va_list *fm)
{
	(*str)++;
	**str == '0' ? skip_zero(str) : 0;
	pf->dot = ft_isdigit(**str) ? ft_atoi_pf(*str) : -1;
	if (**str == '*')
	{
		pf->dot = va_arg(*fm, int);
		if (pf->dot < 0)
		{
			pf->dot = 0;
			(*str)++;
			return (0);
		}
	}
	if (pf->dot != -1)
	{
		pf->len_dot = len_value(pf->dot);
		if (pf->len_dot == 0)
		{
			pf->len_dot++;
			pf->dot = -1;
		}
		(*str) += **str == '*' ? 1 : pf->len_dot;
	}
	return (0);
}

void	precision_s(char *str, int dot, t_pf *pf)
{
	int		len;
	char	*dot_str;

	len = -1;
	dot_str = strnew_pf((size_t)dot, pf);
	dot_str[dot] = '\0';
	while (++len < dot)
		dot_str[len] = str[len];
	pf->str = ft_strdup(dot_str);
	ft_strdel(&dot_str);
	pf->dot = 0;
}

void	create_dot(char *str, int dot, t_pf *pf)
{
	char	*dot_str;
	int		len;
	size_t	i;
	int		end;

	i = ft_strlen(str);
	*str == '-' ? dot++ : 0;
	end = *str == '-' ? 1 : 0;
	len = dot;
	if ((size_t)dot > i && ft_is_int(pf))
	{
		dot_str = strnew_pf((size_t)dot, pf);
		while (dot-- > 0)
			dot_str[dot] = '0';
		while (--len > end && i)
		{
			dot_str[len] = str[--i];
			str[i - 1] == '-' ? i = 0 : 0;
		}
		*str == '-' ? dot_str[0] = '-' : 0;
		pf->str = ft_strdup(dot_str);
		ft_strdel(&dot_str);
		ft_strdel(&str);
	}
	pf->spcr == 's' || pf->spcr == 'S' ? precision_s(pf->str, pf->dot, pf) : 0;
}
