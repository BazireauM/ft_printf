/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:55:57 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 15:18:02 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_s(va_list arg)
{
	char	*s;
	int		i;
	int		c;
	int		b;

	s = va_arg(arg, char *);
	i = 0;
	b = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			c = write(1, &s[i], 1);
			if (c == -1)
				return (-1);
			b += c;
			i++;
		}
	}
	else
	{
		c = write (1, &"(null)", 6);
		if (c == -1)
			return (-1);
		b += c;
	}
	return (b);
}
