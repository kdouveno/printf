#include "ft_printf.h"

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

void	putdouble(double d, int precision){
	long e;

	e = (long)d;
	ft_putnbr(e);
	ft_putchar('.');
	putddouble(d - e, precision);
}

int main(void)
{
	printf("\033[35m%-d\033[37m|%%d\n", -2147);
	ft_printf("\033[36m%-d\033[37m|\n\n", -2147);
	printf("\033[35m%-.15d\033[37m|%%.15d\n", -2147);
	ft_printf("\033[36m%-.15d\033[37m|\n\n", -2147);
	printf("\033[35m%- .15d\033[37m|%% .15d\n", -2147);
	ft_printf("\033[36m%- .15d\033[37m|\n\n", -2147);
	printf("\033[35m%-20d\033[37m|%%20d\n", -2147);
	ft_printf("\033[36m%-20d\033[37m|\n\n", -2147);
	printf("\033[35m%-20d\033[37m|%%020d\n", -2147);
	ft_printf("\033[36m%-20d\033[37m|\n\n", -2147);
	printf("\033[35m%- 20d\033[37m|%% 20d\n", -2147);
	ft_printf("\033[36m%- 20d\033[37m|\n\n", -2147);
	printf("\033[35m%- 20d\033[37m|%%0 20d\n", -2147);
	ft_printf("\033[36m%- 20d\033[37m|\n\n", -2147);

	printf("\033[35m%- 20.15d\033[37m|%% 20.15d\n", -2147);
	ft_printf("\033[36m%- 20.15d\033[37m|\n\n", -2147);
	printf("\033[35m%- 20.5d\033[37m|%% 020.5d\n", -2147);
	ft_printf("\033[36m%- 20.5d\033[37m|\n\n", -2147);

	return 0;
}
