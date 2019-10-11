
#NAME	= bsq

SRCDIR = srcs/

FILES	= main.c read_file.c check_data.c ft_utils.c ft_strjoin.c map_creator.c free_tab.c solve.c print_data.c ft_strdup.c

SRCS	=  $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc

NAME	= bsq

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I includes/

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
