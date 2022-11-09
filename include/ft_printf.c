/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:21:47 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 16:47:10 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		a;
	int		i;
	int		c;
	int		d;

	va_start(arg, s);
	i = 0;
	d = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != '%' && s[i])
		{
			c = write(1, &s[i], 1);
			if (c == -1)
				return (-1);
			a++;
			i++;
		}
		else if (s[i] == '%' && s[i + 1])
		{
			c = choose_type(arg, (char)s[i + 1], &a);
			if (c == -1)
				return (-1);
			i += 2;
		}
		else
			i++;
	}
	return (a);
}
