NAME	= libftprintf.a

FILES = ft_printf.c ft_vprintf.c flag_parsing.c text_format.c

BFILES = 

INCLUDES = includes

SRCS	=  $(FILES)

BSRCS	= $(BFILES)

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BSRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS	= -I ${INCLUDES}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

bonus:	     ${BOBJS} ${NAME}
			ar rc ${NAME} ${OBJS} ${BOBJS}
			ranlib ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
