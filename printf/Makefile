NAME	= libft.a

FILES = 

BFILES = 

SRCS	=  $(FILES)

BSRCS	= $(BFILES)

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BSRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-I includes/

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
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
