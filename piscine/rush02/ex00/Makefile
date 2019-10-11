
SRCS	= main.c ft_utils.c read_dict.c ft_strjoin.c write_number.c ft_strstr.c ft_strncmp.c check_params.c check_dictionary.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= gcc

RM		= rm -f

CFLAGS	=  -I.

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
