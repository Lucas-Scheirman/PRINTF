/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:39:20 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/11 09:39:20 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *y)
{
	int	i;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*y += 6;
		return ;
	}
	i = ft_strlen(s);
	write(fd, s, i);
	*y += i;
}
