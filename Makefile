
NAME =		libftprintf.a
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SRCS =		srcs/ft_printf.c \
				srcs/ft_pf_parsing.c \
				srcs/ft_pf_int.c \
				srcs/ft_pf_uint.c \
				srcs/ft_pf_hex.c \
				srcs/ft_pf_uphex.c \
				srcs/ft_pf_adr.c \
				srcs/ft_pf_char.c \
				srcs/ft_pf_str.c \
				srcs/ft_pf_percent.c \
				srcs/ft_pf_write.c \
				srcs/ft_pf_writemore.c \
				srcs/ft_pf_basicft.c
OBJS =		$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
				ar -rcs $@ $(OBJS)

%.o:		%.c
				$(CC) $(CFLAGS) -I. -o $@ -c $?

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

.PHONY: all, $(NAME), clean, fclean, re
