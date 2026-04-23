/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:07:23 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/21 01:09:26 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	tab_convert(int nb, int fd, int *y)
{
	int		index;
	char	tab_char_int[12];

	index = 0;
	while (nb != 0)
	{
		tab_char_int[index] = (nb % 10) + '0';
		nb = nb / 10;
		index++;
	}
	tab_char_int[index] = '\0';
	index--;
	while (index >= 0)
	{
		write(fd, &tab_char_int[index], 1);
		*y += 1;
		index--;
	}
}

void	ft_putnbr_fd(int nb, int fd, int *y)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*y += 11;
	}
	else if (nb == 0)
	{
		write(fd, "0", 1);
		*y += 1;
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
		*y += 1;
		tab_convert(nb, fd, y);
	}
	else
		tab_convert(nb, fd, y);
}
