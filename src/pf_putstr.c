#include "ft_printf.h"

// void	pf_pstr(char *c, t_params pa)
// {
// 	unsigned long int    i;
//
// 	if (pa.left == 1 && pa.precision == 0)
// 	    pa.width++;
// 	i = 0;
// 	while (c[i])
// 	    ++i;
// 	if ((pa.width > 0 && pa.left == 0 && pa.precision == -1) ||
// 	    (pa.width == 0 && pa.left == 1))
// 	    pf_spaces(pa.width - (int)i);
// 	else if (pa.width > pa.precision && pa.precision > -1 && pa.left == 0)
// 	    pf_spaces(pa.width - pa.precision);
// 	i = 0;
// 	while (c[i] && pa.precision != 0)
// 	{
// 	    pc_putchar(c[i]);
// 	    i++;
// 	    if (pa.precision > 0)
// 	        if ((int)i == pa.precision)
// 	            break ;
// 	}
// 	if (pa.width && pa.left == 1)
// 	    pf_spaces(pa.width - (int)i);
// }

void	pf_pstr(char *c, t_params pa)
{
	int    i;

	i = 0;
	while (c[i])
	    ++i;
	if (!pa.left && pa.precision == -1)
		pf_spaces(pa.width - i);
	else if (!pa.left)
		pf_spaces(pa.width - (((i - pa.precision) < 0 ) ? 0 : i - pa.precision));
	i = 0;
	while (c[i] && (pa.precision == -1 || i < pa.precision))
		pc_putchar(c[i++]);
	if (pa.left)
		pf_spaces(pa.width - i);
}

void    pf_putstr(va_list p, t_params pa)
{
    char*                c;

    c = va_arg(p, char*);
	if (c)
		pf_pstr(c, pa);
	else
		pf_pstr("(null)", pa);
}
