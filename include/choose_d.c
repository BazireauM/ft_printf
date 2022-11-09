/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:06 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 15:06:09 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_d(va_list arg, int *a)
{
	int	d;
	int	b;

	b = va_arg(arg, int);
	d = ft_putnbr(b);
	*a += d;
	return (d);
}

int	ft_putnbr(int n)
{
	unsigned int	n2;
	int				c;
	char			test;

	if (n < 0)
	{
		n2 = -n;
		c = write(1, &"-", 1);
		if (c == -1)
			return (-1);
	}
	else
		n2 = n;
	if (n2 >= 10)
	{
		ft_putnbr(n2 / 10);
		ft_putnbr(n2 % 10);
	}
	else
	{
		test = n2 + '0';
		c = write(1, &test, 1);
	}
	return (c);
}
