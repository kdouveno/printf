/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prlonger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:52:07 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 15:53:01 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	pf_pllong(long long nbr, t_params *pa)
{
	long long min;

	if ((min = (nbr == min_ll())))
	{
		pa->neg = 1;
		pf_pllong((nbr - 1) / pa->base, pa);
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
		pf_pllong(nbr / (long long)pa->base, pa);
	else if (!min)
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base + (min ? 49 : 48));
}

void	pf_putllong(va_list p, t_params pa)
{
	long long nbr;

	pa.width -= 1;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = va_arg(p, long long);
	if (nbr > 0 && !pa.pos)
		pa.width++;
	if (nbr == 0)
			pa.width++;
	if (pa.precision != 0 || nbr != 0)
		pf_pllong(nbr, &pa);
	else
		pa.left = 1;
	if (nbr == min_ll())
	{
		pa.precision--;
		pa.width--;
	}
	if (pa.left)
		pf_spaces(pa.width);
}
