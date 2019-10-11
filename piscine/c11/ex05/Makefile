
SRCS	= main.c op_functions.c ft_utils.c 

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I .

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o  ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
