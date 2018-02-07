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

static void pf_pusizet(size_t nbr, t_params *pa)
{
	pa->width--;
	pa->precision--;
	if ((nbr / pa->base || (pa->precision > 0)
	|| (pa->zero && pa->width > 0)))
		pf_pusizet(nbr / (size_t)pa->base, pa);
	else
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base +  48);
}

void	pf_putusizet(va_list p, t_params pa)
{
	size_t nbr;

	pa.width -= 1;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = va_arg(p, size_t);
	if (nbr > 0 && !pa.pos)
		pa.width++;
	pf_pusizet(nbr, &pa);
	if (pa.left)
		pf_spaces(pa.width);
}
