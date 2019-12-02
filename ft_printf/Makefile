NAME	= libftprintf.a

SRCDIR = srcs/

FILES = ft_printf.c ft_vprintf.c flag_parsing.c text_format.c integer_format.c float_format.c conversions.c utils.c float_utils.c

BFILES = 

INCLUDES = includes

SRCS	=  $(addprefix $(SRCDIR), $(FILES))

BSRCS	= $(BFILES)

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BSRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra -I ${INCLUDES}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C libft
			ar rc ${NAME} ${OBJS} libft/*.o
			ranlib ${NAME}

all:		${NAME}

bonus:	     ${BOBJS} ${NAME}
			ar rc ${NAME} ${OBJS} ${BOBJS}
			ranlib ${NAME}

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
