
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -glldb
RM		= rm -f
NAME	= libft.a
SRCS	=  ft_strchr.c ft_strlen.c ft_strncmp.c ft_charmap_linecounter.c
OBJS	= ${SRCS:.c=.o}
AR		= ar rc

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re: fclean all
.PHONY:	all clean fclean re
