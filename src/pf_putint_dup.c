/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:52:07 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 15:53:01 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putint(va_list p, t_params pa)
{
	int nbr;

	pa.width -= 1;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = va_arg(p, int);
	if ((nbr > 0 && !pa.pos) || nbr == 0)
		pa.width++;
	if (pa.precision != 0 || nbr != 0)
		pf_pint(nbr, &pa);
	else
		pa.left = 1;
	if (nbr == min_i())
		pa.width--;
	if (pa.left)
		pf_spaces(pa.width);
}

void 	pf_pint(int nbr, t_params *pa)
{
	int min;

	if ((min = (nbr == min_i())))
	{
		pa->neg = 1;
		pa->width--;
		pa->precision--;
		pf_pint((nbr - 1) / pa->base, pa);
	}
	if (nbr < 0)
	{
		nbr = min ? nbr - 1 : -nbr;
		if (!min)
			pa->neg = 1;
	}
	pa->width--;
	pa->precision--;
	if ((nbr / pa->base || (pa->precision > 0)
	|| (pa->zero && pa->width > 0)) && !min)
		pf_pint(nbr / (int)pa->base, pa);
	else if (!min)
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base + (min ? 49 : 48));
}
void	pf_prefix(t_params *pa)
{
	if (pa->neg)
		pc_putchar('-');
	else if (pa->pos == 1)
		pc_putchar('+');
	else if (pa->pos == 2)
		pc_putchar(' ');
	else if (pa->hash && pa->base == 8)
		pc_putchar('0');
	else if (pa->hash && pa->base == 16)
	{
		pc_putchar('0');
		pc_putchar(pa->pos == 80 ? 'X' : 'x');
	}
}
//afiche n espace.
void pf_spaces(int n)
{
	while (n > 0)
	{
		pc_putchar(' ');
		n--;
	}
}
