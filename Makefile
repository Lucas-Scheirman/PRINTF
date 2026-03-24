NAME		= libftprintf.a
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f
SRCS		= ft_printf.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putnbr_fd.c \
		  ft_putnbr_base.c \
		  ft_strlen.c
OBJS		= $(SRCS:.c=.o)
all:		$(NAME)
$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)
%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
.PHONY:		all clean fclean re
