/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:07:34 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/21 01:07:36 by lscheirm         ###   ########.fr       */
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
