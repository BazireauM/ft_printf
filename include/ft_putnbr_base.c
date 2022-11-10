/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:23:28 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 13:41:32 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*test_zero(unsigned long long nbr)
{
	char	*final;

	final = NULL;
	if (nbr == 0)
	{
		final = malloc(sizeof(char) * 2);
		if (!final)
			return (NULL);
		final[0] = '0';
		final[1] = '\0';
		return (final);
	}
	return (final);
}

char	*ft_putnbr_base(unsigned long long nbr, char *base)
{
	int					i;
	unsigned long long	a;
	char				*final;

	final = test_zero(nbr);
	if (nbr == 0)
		return (final);
	a = nbr;
	i = 0;
	while (a > 0)
	{
		a /= 16;
		i++;
	}
	final = malloc(sizeof(char) * (i + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (nbr > 0)
	{
		final[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	final[i] = '\0';
	return (final);
}
