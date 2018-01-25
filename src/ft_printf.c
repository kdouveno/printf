/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:54:44 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 11:55:03 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ends	*ft_ends()
{
	static t_ends out[3];
	int i;

	i = 0;
	if (out[0].end == NULL){
		// (t_ends){"hhd", &pf_putchard};
		// (t_ends){"hhu", &pf_uchard};
		// (t_ends){"lld", &pf_putllong};
		// (t_ends){"llu", &pf_putullong};
		// (t_ends){"llf", &pf_putdouble};
		// (t_ends){"hd", &pf_putshort};
		// (t_ends){"ld", &pf_putlong};
		// (t_ends){"zd", &pf_putsizet};
		// (t_ends){"jd", &pf_putintmax};

		// (t_ends){"hu", &pf_putushort};
		// (t_ends){"lu", &pf_putulong};
		// (t_ends){"zu", &pf_putusizet};
		// (t_ends){"ju", &pf_putuintmax};
		// (t_ends){"lf", &pf_putdouble};
		out[i++] = (t_ends){"d", &pf_putint};
		out[i++] = (t_ends){"f", &pf_putdouble};
		out[i++] = (t_ends){"s", &pf_putstring};
		// (t_ends){"u", &pf_putuint};
		// (t_ends){"m", &pf_putmemory};
		// (t_ends){"b", &pf_putbmemory};
	}
	return out;
}

int				ft_printf(char *format, ...)
{
	va_list p;
	int i;

	i = 0;

	va_start(p, format);
	while (format[i])
	{
		if (format[i] != '%'){
			pc_putchar(format[i++]);
		}
		else{
			pf_parse(format, &i, p);
		}
	}
	return pc_print();
}

void			pf_parse(char *format, int *i, va_list p)
{
	t_params	pa;

	pa = (t_params){0,0,10,0,0,0,0};
	(void)p;
	i[0]++;
	get_flags(format, i, &pa);
	pa.width = get_width(format, i, p);
	pa.precision = get_precision(format, i, p);
	pf_launch(format, i, &pa, p);

}

void			pf_launch(char *fo, int *i, t_params *pa, va_list p)
{
	int j;
	int k;

	j = 0;

	while (j < 3)
	{
		k = 0;
		while (ft_ends()[j].end[k] && ft_ends()[j].end[k] == fo[*i + k])
			k++;
		if (!ft_ends()[j].end[k])
		{
			ft_ends()[j].f(p, *pa);
			(*i) += ft_strlen(ft_ends()[j].end);
			return ;
		}
		j++;
	}
}

void			get_flags(char *fo, int *i, t_params *pa)
{
	while (ft_strchr("-+0 #", fo[*i]))
	{
		if (fo[*i] == '-')
			pa->left = 1;
		else if (fo[*i] == '+')
			pa->pos = 1;
		else if (fo[*i] == '0')
			pa->zero = 1;
		else if (fo[*i] == ' ' && pa->pos != 1)
			pa->pos = 2;
		i[0]++;
	}
}

int				get_width(char *fo, int *i, va_list p)
{
	int j;

	j = 0;
	if (fo[*i] == '*')
		return (va_arg(p, int));
	while (fo[*i + j] >= '0' && fo[*i + j] <= '9')
		j++;
	i[0] += j;
	if (j != 0)
		return (ft_atoi(fo + *i - j));
	return (0);
}

int				get_precision(char *fo, int *i, va_list p)
{
	int j;

	j = 0;
	if (fo[*i] == '.')
	{
		i[0]++;
		if (fo[*i] == '*')
			return (va_arg(p, int));
		while (fo[*i + j] >= '0' && fo[*i + j] <= '9')
			j++;
		i[0] += j;
		return (ft_atoi(fo + *i - j));
	}
	return (-1);
}
// unsigned int	get_precision(char *fo, int *i, va_list p)
// {
//
// }
// void			get_end(char *fo, int *i)
// {
//
// }
