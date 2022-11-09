/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_xmaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:31:11 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 17:41:56 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_xmaj(va_list arg, int *a)
{
	unsigned int	b;
	char			*test;
	int				c;
	int				i;

	b = va_arg(arg, unsigned int);
	test = ft_putnbr_base(b, "0123456789ABCDEF");
	i = 0;
	if (test == NULL)
	{
		free(test);
		return (-1);
	}
	while (test[i])
		i++;
	i--;
	while (i >= 0)
	{
		c = write(1, &test[i], 1);
		if (c == -1)
		{
			free(test);
			return (-1);
		}
		*a += c;
		i--;
	}
	free(test);
	return (0);
}
