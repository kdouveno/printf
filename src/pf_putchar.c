/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:52:44 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/19 12:28:41 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*widen(char *old, int pos) {
	char *out;

	if (!(out = (char*)malloc((pos / BS + 1) * BS + 1)))
		return (NULL);
	ft_bzero(out, (pos / BS + 1) * BS + 1);
	if (old)
	{
		ft_memcpy(out, old, (pos / BS) * BS);
		free(old);
	}
	return (out);
}

static int		pc_core(char c, int param)
{
	static int			pos;
	static char 		*buffer;
	int					out;

	if (param)
	{
		if (!(pos % BS))
			if (!(buffer = widen(buffer, pos)))
				return (-1);
		buffer[pos] = c;
		pos++;
	}
	else
	{
		write(1, buffer, (out = ft_strlen(buffer)));
		free(buffer);
		buffer = NULL;
		pos = 0;
		return (out);
	}
	return (0);
}

int		pc_print(void)
{
	return (pc_core(0, 0));
}

void	pc_putchar(char c)
{
	pc_core(c, 1);
}

void	pc_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		pc_core(str[i], 1);
		i++;
	}
}
