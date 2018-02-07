#include "ft_printf.h"

void ft_intuni(int c)
{
	if (c < (1 << 7))
		pc_putchar((char)c);
	else if (c < (1 << 11))
	{
		pc_putchar((char)(0xC0 | ((c & (0x1f << 6)) >> 6)));
		pc_putchar((char)(0x80 | (c & 0x3f)));
	}
	else if (c < (1 << 16))
	{
		pc_putchar((char)(0xe0 | ((c & (0x0f << 12)) >> 12)));
		pc_putchar((char)(0x80 | ((c & (0x3f << 6)) >> 6)));
		pc_putchar((char)(0x80 | (c & 0x3f)));
	}
	else if (c < (1 << 21))
	{
		pc_putchar((char)(0xF0 | ((c & (0x07 << 18)) >> 18)));
		pc_putchar((char)(0x80 | ((c & (0x3f << 12)) >> 12)));
		pc_putchar((char)(0x80 | ((c & (0x3f << 6)) >> 6)));
		pc_putchar((char)(0x80 | (c & 0x3f)));
	}
}

int		ft_miw(int c)
{
	if (c < (1 << 7))
		return (1);
	else if (c < (1 << 11))
		return (2);
	else if (c < (1 << 16))
		return (3);
	else if (c < (1 << 21))
		return (4);
	return (0);
}

void	pf_putuni(va_list p, t_params pa)
{
	int *str;
	int len;
	int pre;
	int i;
	int j;

	i = 0;
	str = va_arg(p, int*);
	len = 0;
	pre = pa.precision;
	while (str[i] && (pa.precision == -1 || (pre = pre - ft_miw(str[i])) >= 0))
		len += ft_miw(str[i++]);
	pa.width -= len;
	if (!pa.left)
		pf_spaces(pa.width);
	j = 0;
	while (j < i)
		ft_intuni(str[j++]);
	if (pa.left)
		pf_spaces(pa.width);
}



/*
0xxxxxxx
110xxxxx 10xxxxxx
1110xxxx 10xxxxxx 10xxxxxx
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/
