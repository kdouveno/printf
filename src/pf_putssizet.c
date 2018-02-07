#include "ft_printf.h"

static void 	pf_psizet(size_t nbr, t_params *pa)
{
	size_t min;

	if ((min = (nbr == min_i())))
	{
		pa->neg = 1;
		pa->width--;
		pa->precision--;
		pf_psizet((nbr - 1) / pa->base, pa);
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
		pf_psizet(nbr / (size_t)pa->base, pa);
	else if (!min)
	{
		if (!pa->zero && !pa->left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->base + (min ? 49 : 48));
}

void	pf_putsizet(va_list p, t_params pa)
{
	size_t nbr;

	pa.width -= 1;
	if (pa.left || pa.precision != -1)
		pa.zero = 0;
	nbr = va_arg(p, size_t);
	if (nbr > 0 && !pa.pos)
		pa.width++;
	if (nbr == 0)
			pa.width++;
	if (pa.precision != 0 || nbr != 0)
		pf_psizet(nbr, &pa);
	else
		pa.left =	 1;
	if (nbr == min_i())
	{
		pa.precision--;
		pa.width--;
	}
	if (pa.left)
		pf_spaces(pa.width);
}
