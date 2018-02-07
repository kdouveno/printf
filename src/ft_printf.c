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
	static t_ends out[41];
	int i;

	i = 0;
	if (out[0].end == NULL)
	{
		out[i++] = (t_ends){"lld", &pf_putllong};
		out[i++] = (t_ends){"hhd", &pf_putchard};
		out[i++] = (t_ends){"hhu", &pf_putuchard};
		out[i++] = (t_ends){"llu", &pf_putullong};
		out[i++] = (t_ends){"hhx", &pf_putxchard};
		out[i++] = (t_ends){"llx", &pf_putxllong};
		out[i++] = (t_ends){"hhX", &pf_putmxchard};
		out[i++] = (t_ends){"llX", &pf_putmxllong};

		out[i++] = (t_ends){"hd", &pf_putshort};
		out[i++] = (t_ends){"ld", &pf_putlong};
		out[i++] = (t_ends){"zd", &pf_putllong};
		out[i++] = (t_ends){"jd", &pf_putllong};

		out[i++] = (t_ends){"ls", &pf_putuni};
		out[i++] = (t_ends){"lc", &pf_putcuni};

		out[i++] = (t_ends){"lu", &pf_putulong};
		out[i++] = (t_ends){"hu", &pf_putushort};
		out[i++] = (t_ends){"ju", &pf_putullong};
		out[i++] = (t_ends){"zu", &pf_putullong};
		out[i++] = (t_ends){"lU", &pf_putullong};
		out[i++] = (t_ends){"hU", &pf_putullong};

		out[i++] = (t_ends){"hx", &pf_putxshort};
		out[i++] = (t_ends){"lx", &pf_putxlong};
		out[i++] = (t_ends){"jx", &pf_putxllong};
		out[i++] = (t_ends){"zx", &pf_putxllong};

		out[i++] = (t_ends){"hX", &pf_putmxshort};
		out[i++] = (t_ends){"lX", &pf_putmxlong};
		out[i++] = (t_ends){"jX", &pf_putmxllong};
		out[i++] = (t_ends){"zX", &pf_putmxllong};

		out[i++] = (t_ends){"d", &pf_putint};
		out[i++] = (t_ends){"o", &pf_putoint};
		out[i++] = (t_ends){"x", &pf_putxint};
		out[i++] = (t_ends){"X", &pf_putmxint};
		out[i++] = (t_ends){"p", &pf_putpointer};
		out[i++] = (t_ends){"f", &pf_putdouble};
		out[i++] = (t_ends){"S", &pf_putuni};
		out[i++] = (t_ends){"s", &pf_putstr};
		out[i++] = (t_ends){"C", &pf_putcuni};
		out[i++] = (t_ends){"c", &pf_putc};
		out[i++] = (t_ends){"u", &pf_putuint};
		out[i++] = (t_ends){"U", &pf_putullong};
		out[i++] = (t_ends){"%", &pf_escape};

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

	pa = (t_params){0, 0, 10, 0, 0, 0, 0, 0};
	(void)p;
	i[0]++;
	get_flags(format, i, &pa);
	pa.width = get_width(format, i, p);
	pa.precision = get_precision(format, i, p);
	pf_launch(format, i, &pa, p);

}

void			pf_escape(va_list p, t_params pa)
{
	(void)p;
	if (!pa.left)
		pf_spaces(pa.width - 1);
	pc_putchar('%');
	if (pa.left)
		pf_spaces(pa.width - 1);
}

void			pf_launch(char *fo, int *i, t_params *pa, va_list p)
{
	int j;
	int k;

	j = 0;

	while (j < 41)
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
		else if (fo[*i] == '#')
				pa->hash = 1;
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
