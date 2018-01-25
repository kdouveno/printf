#include "ft_printf.h"

static void	pc_putnbr(int n)
{
	if (n == -2147483647 - 1)
	{
		pc_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		pc_putchar('-');
	}
	if (n / 10)
		pc_putnbr(n / 10);
	pc_putchar(n % 10 + 48);
}


static void	putddouble(double d, int precision) {
	char e;

	d *= 10;
	e = (char)d;
	d -= e;
	pc_putchar(e + 48);
	precision--;
	if (precision)
		putddouble(d, precision);
}

static void	pdouble(double d, int precision){
	long e;

	e = (long)d;
	pc_putnbr(e);
	pc_putchar('.');
	putddouble(d - e, precision);
}

void		pf_putdouble(va_list p, t_params pa)
{
	if (pa.precision == -1)
		pa.precision = 6;
	pdouble(va_arg(p, double), pa.precision);
}
