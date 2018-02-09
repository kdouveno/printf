#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

void	putddouble(double d, int precision) {
	char e;

	d *= 10;
	e = (char)d;
	d -= e;
	pc_putchar(e + 48);
	precision--;
	if (precision)
		putddouble(d, precision);
}

void	putdouble(double d, int precision)
{
	long e;

	e = (long)d;
	ft_putnbr(e);
	ft_putchar('.');
	putddouble(d - e, precision);
}

int		main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("\033[35m%010.5d\n", 0);
	printf("\033[36m%010.5d\n", 0);
	return 0;
}
