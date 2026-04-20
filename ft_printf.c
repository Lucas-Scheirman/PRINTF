/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:10:34 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/21 00:20:21 by lscheirm         ###   ########.fr       */
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
	ft_putnbr_base((uintptr_t)arg, "0123456789abcdef", y);
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
		ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789", y);
	else if (c == 'x')
		ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef", y);
	else if (c == 'X')
		ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF", y);
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
	if (!format)
		return (-1);
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
/*
#include <stdio.h>

int	main(void)
{

	int	x;
	x = 42;
	printf("sdfs\n");
	ft_printf("sdfs\n");
	printf(NULL);

	// %c
	ft_printf("%c\n", 'A');
	printf("%c\n", 'A');
	// %s
	ft_printf("%s\n", "bonjour");
	printf("%s\n", "bonjour");
	// %s NULL
	ft_printf("%s\n", NULL);
	printf("%s\n", (char *)NULL);
	// %p
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	// %p valeur reelle

	ft_printf("%p\n", &x);
	printf("%p\n", &x);
	// %d
	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	// %d negatif
	ft_printf("%d\n", -42);
	printf("%d\n", -42);
	// %i
	ft_printf("%i\n", 42);
	printf("%i\n", 42);
	// %u
	ft_printf("%u\n", 42);
	printf("%u\n", 42);
	// %u grand nombre
	ft_printf("%u\n", 5294967295);
	printf("%u\n", (unsigned int)5294967295);
	// %x
	ft_printf("%x\n", 255);
	printf("%x\n", 255);
	// %X
	ft_printf("%X\n", 255);
	printf("%X\n", 255);
	// %%
	ft_printf("%%\n");
	printf("%%\n");
	// INT_MIN
	ft_printf("%d\n", -2147483648);
	printf("%d\n",(unsigned int ) -2147483648);

	// %u avec 0
	ft_printf("%u\n", 0);
	printf("%u\n", 0);

	// %x avec 0
	ft_printf("%x\n", 0);
	printf("%x\n", 0);

	// %X avec 0
	ft_printf("%X\n", 0);
	printf("%X\n", 0);

	// %s string vide
	ft_printf("%s\n", "");
	printf("%s\n", "");

	// %c nul
	ft_printf("%c\n", '\0');
	printf("%c\n", '\0');
	return (0);
}*/
