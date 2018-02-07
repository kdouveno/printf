#include "ft_printf.h"

void	pf_putcuni(va_list p, t_params pa)
{
	int c;

	c = va_arg(p, int);
	pa.width -= ft_miw(c);
	if (!pa.left)
		pf_spaces(pa.width);
	ft_intuni(c);
	if (pa.left)
		pf_spaces(pa.width);
}
