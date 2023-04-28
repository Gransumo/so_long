CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -glldb
LINKS		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f
NAME		= so_long
SRCS		= main.c error.c print_map.c close.c hooks.c moves.c $(SRC_GNL) $(SRC_MAP)
OBJS		= ${SRCS:.c=.o}
AR			= ar rc

LIBFT_DIR	= libft/
LIBFT_A		= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

PRINTF_DIR	= Printf/
PRINTF_A	= printf.a
PRINTF		= $(addprefix $(PRINTF_DIR), $(PRINTF_A))

MAP			= check_map.c map_utils.c map_reader.c check_map_path.c tilemap_generator.c
SRC_MAP		= $(addprefix check_map/, $(MAP))

GNL			= get_next_line.c get_next_line_utils.c
SRC_GNL		= $(addprefix gnl/, $(GNL))


%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:	${NAME}

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LINKS) -o $(NAME)


#$(OBJS): $(SRCS)
#	$(CC) $(FLAGS) -c $(SRCS)
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
re: fclean all
.PHONY:	all clean fclean re
