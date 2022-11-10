/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:21:47 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 13:54:00 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	struct s_norm	test;

	va_start(arg, s);
	test.i = 0;
	test.d = 0;
	test.a = 0;
	if (s == NULL)
		return (-1);
	while (s[test.i])
	{
		if (s[test.i] != '%' && s[test.i])
		{
			test.c = write(1, &s[test.i], 1);
			if (test.c == -1)
				return (-1);
			test.a++;
			test.i++;
		}
		else if (s[test.i] == '%' && s[test.i + 1])
		{
			test.c = choose_type(arg, (char)s[test.i + 1], &test.a);
			if (test.c == -1)
				return (-1);
			test.i += 2;
		}
		else
			test.i++;
	}
	return (test.a);
}
