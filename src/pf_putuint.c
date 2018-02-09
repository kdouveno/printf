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

static void pf_puint(unsigned int nbr, t_params *pa)
{
	pa->width--;
	pa->precision--;
	if ((nbr / pa->base || (pa->precision > 0)
	|| (pa->zero && pa->width > 0)))
		pf_puint(nbr / (unsigned int)pa->base, pa);
	else
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base +  48);
}

void	pf_putuint(va_list p, t_params pa)
{
	unsigned int nbr;

	pa.width -= 1;
	pa.pos = 0;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = va_arg(p, unsigned int);
	if (nbr > 0)
		pa.width++;
	pf_puint(nbr, &pa);
	if (pa.left)
		pf_spaces(pa.width);
}
