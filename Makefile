NAME	=	libftprintf.a

SRCS	=	include/ft_printf.c\
			include/choose_%.c\
			include/check_error.c\
			include/choose_c.c\
			include/choose_d.c\
			include/choose_p.c\
			include/choose_s.c\
			include/choose_type.c\
			include/choose_u.c\
			include/choose_x.c\
			include/choose_xmaj.c\
			include/ft_itoa_u.c\
			include/ft_parssing_input.c\
			include/ft_putnbr_base.c\
			include/print_table_table.c\
			include/ft_itoa.c\
			include/ft_strlen.c\
			include/ft_putstr_fd.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	= -Wall -Werror -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean	:	
		$(RM) $(OBJS)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean $(NAME)
