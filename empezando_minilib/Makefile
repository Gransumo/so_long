CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -glldb
LINKS		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -rf
NAME		= mlx_pract.out
SRCS		= main.c
OBJS		= ${SRCS:.c=.o}
ar			= ar rc

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LINKS} -o ${NAME}

clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re