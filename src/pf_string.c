#include "ft_printf.h"

void	pf_putstring(va_list p, t_params pa)
{
	char *str;

	if (pa.left)
		pa.zero = 0;
	str = (char*)va_arg(p, char*);
	pc_putstr(str);
	if (pa.left)
		pf_spaces(pa.width);
}
