/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:06 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 16:50:51 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_d(va_list arg, int *a)
{
	int		b;
	int		i;
	int		c;
	char	*test;

	b = va_arg(arg, int);
	test = ft_itoa(b);
	i = 0;
	if (test == NULL)
	{
		free(test);
		return (-1);
	}
	while (test[i])
	{
		c = write(1, &test[i], 1);
		if (c == -1)
		{
			free(test);
			return (-1);
		}
		*a += c;
		i++;
	}
	free(test);
	return (0);
}
/*
int	ft_putnbr(int n, int *a)
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
		*a += c;
	}
	else
		n2 = n;
	if (n2 >= 10)
	{
		ft_putnbr(n2 / 10, a);
		ft_putnbr(n2 % 10, a);
	}
	else
	{
		test = n2 + '0';
		c = write(1, &test, 1);
		if (c == -1)
			return (-1);
		*a += c;
	}
	return (0);
}
*/
