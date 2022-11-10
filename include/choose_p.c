/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:35:27 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 14:04:46 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_p(va_list arg, int *a)
{
	unsigned long long	b;
	char				*test;
	int					c;
	int					i;

	b = va_arg(arg, unsigned long long);
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
	c = write(1, &"0x", 2);
	if (c == -1)
	{
		free(test);
		return (-1);
	}
	*a += c;
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
