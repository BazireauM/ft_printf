/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:26:16 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 12:56:05 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_error_arg1(const char *s)
{
	int	a;

	a = 0;
	while (s[a])
	{
		if (s[a] == '%')
		{
			if (s[a + 1])
			{
				if (check_exist(s[a + 1]) == 1)
					return (1);
				a++;
			}
			else
				return (1);
		}
		a++;
	}
	return (0);
}

int	check_exist(char c)
{
	char	*s;
	int		i;

	s = "cspdiuxX%";
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}
