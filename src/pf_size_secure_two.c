#include "ft_printf.h"

size_t	min_st()
{
	static size_t a;

	if (!a)
		a = ((size_t)1 << (sizeof(size_t) * 8 - 1));
	return (a);
}

intmax_t	min_im()
{
	static intmax_t a;

	if (!a)
		a = ((intmax_t)1 << (sizeof(intmax_t) * 8 - 1));
	return (a);
}
