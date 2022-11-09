/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:02:29 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 16:41:47 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_type(va_list arg, char c, int *a)
{
	int	d;

	d = 0;
	if (c == 'c')
		d = choose_c(arg, a);
	else if (c == '%')
		d = choose_for_100(a);
	else if (c == 's')
		d = choose_s(arg, a);
	else if (c == 'd')
		d = choose_d(arg, a);
	else if (c == 'i')
		d = choose_d(arg, a);
	else if (c == 'u')
		d = choose_u(arg, a);
	/*
	else if (c == 'x')
		d = choose_x(arg);
	else if (c == 'X')
		d = choose_xmaj(arg);
	else if (c == 'p')
		d = choose_p(arg);
	*/
	if (d == -1)
		return (-1);
	return (0);
}
