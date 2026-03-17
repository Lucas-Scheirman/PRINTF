/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:39:20 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/11 09:39:20 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	tab_convert(int nb, int fd)
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
		index--;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb == 0)
		write(fd, "0", 1);
	else if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
		tab_convert(nb, fd);
	}
	else
		tab_convert(nb, fd);
}
