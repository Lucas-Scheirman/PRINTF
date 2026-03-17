/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:10:34 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/17 12:09:01 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t i;
	char * str;
	i=0;

	va_start(ap, format);
	while (format[i])
	{
			if(format[i]!='%')
				{ft_putchar_fd(format[i],1);
				i++;}
			else
			{
				print_good_type(format[i],&ap);
				i++;
			}

	}
	va_end(ap);
	return 0;
}
void print_good_type(char c,va_list *ap)
{
	char *str;
				if(c=='c')
					ft_putchar_fd(va_arg(*ap,int),1);
				else if(c=='s')
					ft_putstr(va_arg(*ap,char *));
				else if(c=='p')
					ft_atoi_base((char*) va_arg(*ap,char *),"0123456789ABCDEF");
				else if(c=='d')

				else if(c=='i')
					ft_putnbr_fd(va_arg(*ap,int),1);
				else if(c=='u')
				else if(c=='x')
				else if(c=='X')
				else if(c=='%')
					ft_putchar_fd('%',1);
}
int main()
{
	ft_printf("dsfsfsf");
}
/*%c → Affiche un caractère unique.

			%s → Affiche une chaîne de caractères (selon la convention classique du C).

			%p → L’argument de type pointeur (void *) doit être affiché en format hexadécimal.

			%d → Affiche un nombre décimal (base 10).

			%i → Affiche un entier en base 10.

			%u → Affiche un nombre décimal non signé (base 10).

			%x → Affiche un nombre en hexadécimal (base 16) en minuscules.

			%X → Affiche un nombre en hexadécimal (base 16) en majuscules.

			%% → Affiche le caractère %.*/
