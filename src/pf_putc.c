#include "ft_printf.h"

void			pf_putc(va_list p, t_params pa)
{
	char c;

	c = (char)va_arg(p, int);
	if (!pa.left)
		pf_spaces(pa.width - 1);
	pc_putchar(c);
	if (pa.left)
		pf_spaces(pa.width - 1);
}
