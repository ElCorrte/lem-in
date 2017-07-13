/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:31:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/06/08 15:17:35 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include "../libft.h"

# define RC "\x1B[0m"

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"

typedef struct		s_pf
{
	char			*str;
	int				str_clean;
	char			*s_p;
	char			*f_l;
	char			*is_int;
	int				fd;
	char			spcr;
	intmax_t		value;
	int				sharp_true;
	int				sharp;
	int				zero;
	int				dash;
	int				dash_true;
	int				plus;
	int				space;
	intmax_t		width;
	int				new_width;
	int				len_width;
	intmax_t		dot;
	int				len_dot;
	int				print_smb;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				no_mod;
	int				plus_one;
	int				cnt;
}					t_pf;

int					check_dot(t_pf *pf, const char **str, va_list *fm);
int					check_width(t_pf *pf, const char **str, va_list *fm);
int					ft_check_sp(char sp, va_list *fm, t_pf *pf);
int					ft_printf(const char *format, ...);
int					len_for_width(t_pf *pf);
int					len_value(intmax_t value);
void				clean_all(t_pf *pf);
void				create_dot(char *str, int dot, t_pf *pf);
void				ft_check_smb(int s, t_pf *pf);
void				ft_itoa_dec(intmax_t value, t_pf *pf);
void				ft_mod_d_i(va_list *fm, t_pf *pf);
void				ft_mod_other(va_list *fm, t_pf *pf, int key, int x);
int					ft_plus_space(t_pf *pf);
void				ft_sharp(t_pf *pf);
void				ft_trunk(t_pf *pf);
void				itoa_hex_oct(uintmax_t value, t_pf *pf, int base, int x);
void				print_wchar(va_list *fm, t_pf *pf);
void				print_width(int minus, t_pf *pf);
void				putchar_pf(char c, t_pf *pf);
void				putstr_pf(char const *s, t_pf *pf);
void				use_flag(t_pf *pf);
char				*strnew_pf(size_t size, t_pf *pf);
void				print_c_big(va_list *fm, t_pf *pf);
void				print_c(va_list *fm, t_pf *pf);
void				remove_unnecessary(t_pf *pf);
intmax_t			ft_atoi_pf(const char *str);
int					skip_zero(const char **fl);
int					zero_space_plus(t_pf *pf);

void				print_three_bytes(int tmp, int *i, t_pf *pf);
void				print_four_bytes(int tmp, int *i, t_pf *pf);
char				*add_to_string(char *str, char symb);

#endif
