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

static void pf_puchard(unsigned char nbr, t_params *pa)
{
	pa->width--;
	pa->precision--;
	if ((nbr / pa->base || (pa->precision > 0)
	|| (pa->zero && pa->width > 0)))
		pf_puchard(nbr / (unsigned char)pa->base, pa);
	else
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base +  48);
}

void	pf_putuchard(va_list p, t_params pa)
{
	unsigned char nbr;

	pa.width -= 1;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = (unsigned char)va_arg(p, int);
	if (nbr > 0 && !pa.pos)
		pa.width++;
	pf_puchard(nbr, &pa);
	if (pa.left)
		pf_spaces(pa.width);
}
