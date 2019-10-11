
SRCS	= tail.c ft_atoi.c ft_strjoin.c ft_strlen.c error.c ft_strcmp.c args_format.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

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
