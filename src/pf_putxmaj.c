#include "ft_printf.h"

void	pf_putmxint(va_list p, t_params pformat)
{
	pformat.pos = 80;
	pf_putxint(p, pformat);
}
void	pf_putmxshort(va_list p, t_params pformat)
{
	pformat.pos = 80;
	pf_putxshort(p, pformat);
}
void	pf_putmxchard(va_list p, t_params pformat)
{
	pformat.pos = 80;
	pf_putxchard(p, pformat);
}
void	pf_putmxlong(va_list p, t_params pformat)
{
	pformat.pos = 80;
	pf_putxlong(p, pformat);
}
void	pf_putmxllong(va_list p, t_params pformat)
{
	pformat.pos = 80;
	pf_putxllong(p, pformat);
}
