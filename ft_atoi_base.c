/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:37:09 by lucas             #+#    #+#             */
/*   Updated: 2026/03/17 12:05:21 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isspace_pass(char *str)
{
	int	i;

	i = 0;
	while ((str[i]) && (str[i] <= 32))
		i++;
	return (i);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	calculate_nbr(char *str, char *base, int i, int neg)
{
	int	j;
	int	nb;
	int	len_base;

	nb = 0;
	len_base = str_len(base);
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				nb = (nb * len_base) + (j);
				break ;
			}
			j++;
		}
		if (base[j] == '\0')
			break;
		i++;
	}
	if (neg % 2 == 1)
		return (-nb);
	return (nb);
}

int	base_true(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str_len(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32)
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
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	i;

	neg = 0;
	i = isspace_pass(str);
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	if (!(base_true(base)))
	{
		return (0);
	}
	return (calculate_nbr(str, base, i, neg));
}
