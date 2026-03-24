/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:10:34 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/18 01:29:32 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_p(void *arg, int *y)
{
	if (arg == NULL)
	{
		ft_putstr_fd("(nil)", 1, y);
		return ;
	}
	ft_putstr_fd("0x", 1, y);
	ft_putnbr_base((unsigned long)arg, "0123456789abcdef", y);
}

static void	print_good_type(char c, va_list *ap, int *y)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*ap, int), 1, y);
	else if (c == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1, y);
	else if (c == 'p')
		printf_p(va_arg(*ap, void *), y);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(*ap, int), 1, y);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(*ap, int), 1, y);
	else if (c == 'u')
		ft_putnbr_base((unsigned long)va_arg(*ap, unsigned int), "0123456789",
			y);
	else if (c == 'x')
		ft_putnbr_base((unsigned long)va_arg(*ap, unsigned int),
			"0123456789abcdef", y);
	else if (c == 'X')
		ft_putnbr_base((unsigned long)va_arg(*ap, unsigned int),
			"0123456789ABCDEF", y);
	else if (c == '%')
		ft_putchar_fd('%', 1, y);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		y;

	y = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1, &y);
		else
		{
			i++;
			print_good_type(format[i], &ap, &y);
		}
		i++;
	}
	va_end(ap);
	return (y);
}
