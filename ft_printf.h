/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:26:10 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/21 00:22:25 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd, int *y);
int		ft_printf(const char *format, ...);
void	ft_putnbr_fd(int nb, int fd, int *y);
void	ft_putstr_fd(char *s, int fd, int *y);
void	ft_putnbr_base(unsigned long nbr, char *base, int *y);
int		ft_strlen(const char *s);

#endif
