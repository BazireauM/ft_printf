/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:19:25 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 17:40:21 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_x(va_list arg, int *a)
{
	unsigned int	b;
	char			*test;
	int				c;
	int				i;

	b = va_arg(arg, unsigned int);
	test = ft_putnbr_base(b, "0123456789abcdef");
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
