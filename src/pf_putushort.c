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

static void pf_pushort(unsigned short nbr, t_params *pa)
{
	pa->width--;
	pa->precision--;
	if ((nbr / pa->base || (pa->precision > 0)
	|| (pa->zero && pa->width > 0)))
		pf_pushort(nbr / (unsigned short)pa->base, pa);
	else
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base +  48);
}

void	pf_putushort(va_list p, t_params pa)
{
	unsigned short nbr;

	pa.width -= 1;
	pa.pos = 0;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = (unsigned short)va_arg(p, int);
	if (nbr > 0 && !pa.pos)
		pa.width++;
	pf_pushort(nbr, &pa);
	if (pa.left)
		pf_spaces(pa.width);
}
