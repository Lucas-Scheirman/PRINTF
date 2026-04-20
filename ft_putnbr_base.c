/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:07:16 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/21 01:07:18 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_true(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

static void	write_base_convert(char *tab_result, int j, int *y)
{
	while (j >= 0)
	{
		write(1, &tab_result[j], 1);
		*y += 1;
		j--;
	}
}

static void	write_result(int i, unsigned long nbr, char *base, int *y)
{
	char	tab_result[64];
	int		j;

	j = 0;
	while (nbr != 0)
	{
		tab_result[j] = base[nbr % i];
		nbr = nbr / i;
		j++;
	}
	tab_result[j] = '\0';
	write_base_convert(tab_result, j - 1, y);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int *y)
{
	int	i;

	if ((base[0] == '\0') || (base[1] == '\0'))
		return ;
	i = base_true(base);
	if (i == 0)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		*y += 1;
		return ;
	}
	write_result(i, nbr, base, y);
}
