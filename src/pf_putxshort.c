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

static void pf_pxshort(unsigned short nbr, t_params *pa)
{
	pa->width--;
	pa->precision--;
	if ((nbr / pa->base || (pa->precision > 0)
	|| (pa->zero && pa->width > 0)))
		pf_pxshort(nbr / (unsigned short)pa->base, pa);
	else
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	if (pa->pos == 80)
		pc_putchar(nbr % pa->base + (nbr % pa->base > 9 ? 55 : 48));
	else
		pc_putchar(nbr % pa->base + (nbr % pa->base > 9 ? 87 : 48));
}

void	pf_putxshort(va_list p, t_params pa)
{
	unsigned short nbr;

	pa.base = 16;
	if (pa.pos != 80)
		pa.pos = 0;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	if (pa.hash == 1)
		pa.width -= 2;
	nbr = (unsigned short)va_arg(p, unsigned long);
	if (pa.precision != 0 || nbr != 0 || pa.hash)
	{
		if (pa.hash && !nbr && !(pa.hash = 0))
			pa.width += 2;
		pf_pxshort(nbr, &pa);
	}
	else
		pa.left = 1;
	if (pa.left)
		pf_spaces(pa.width);
}
