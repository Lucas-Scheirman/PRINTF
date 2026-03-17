#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
void	ft_putchar_fd(char c, int fd);
int ft_printf(const char *format, ...);
void	ft_putnbr_fd(int nb, int fd);
void ft_putstr(char * str);
void	ft_putnbr_base(int nbr, char *base);
int	ft_atoi_base(char *str, char *base);

#endif
