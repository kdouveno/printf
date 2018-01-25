/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:17:56 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 14:18:03 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# define BS 8

typedef struct	s_params
{
	int				width;
	int				precision;
	unsigned short	base;
	unsigned short	left;
	unsigned short	neg;
	unsigned short	pos;
	unsigned short	zero;
}				t_params;

typedef struct	s_ends
{
	char *end;
	void (*f)(va_list, t_params);
}				t_ends;

void			pc_putchar(char c);
int				pc_print(void);
void			pc_putstr(char *str);

void			get_flags(char *fo, int *i, t_params *pa);
int				get_width(char *fo, int *i, va_list p);
void			get_end(char *fo, int *i);
int				get_precision(char *fo, int *i, va_list p);
void			pf_launch(char *fo, int *i, t_params *pa, va_list p);

int				ft_printf(char *format, ...);
short			is_flag(char c);
short			is_length(char c);

void			pf_parse(char *f, int *i, va_list p);
void			pf_pint(int nbr, t_params *pa);
void			pf_putint(va_list p, t_params pformat);

void			pf_putdouble(va_list p, t_params pformat);

void			pf_putstring(va_list p, t_params pa);

void			pf_putuint(va_list p, t_params pformat);
void			pf_putshort(va_list p, t_params pa);
void 			pf_pshort(short nbr, t_params *pa);
void			pf_putchard(va_list p, t_params pa);
void			pf_pchard(char nbr, t_params *pa);
void			pf_putlong(va_list p, t_params pa);
void			pf_plong(long nbr, t_params *pa);
void			pf_putc(va_list p, t_params pformat);
void			pc_fill(t_params *pa);
long long		min_ll();
void			pf_prefix(t_params *pa);
void			pf_spaces(int width);
long long		min_ll();
long			min_l();
int				min_i();
short			min_s();
char			min_c();

#endif
