NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./mlx -lmlx -lXext -lX11 -lm -lz -L/usr/include -Imlx
LIBFT = ./libft/libft.a
RM = rm -rf
INCLUDE = -I./libft -I./usr/include
SRCS =	main.c \
		./parsing/arguments.c \
		./parsing/get_next_line.c \
		./parsing/parse_map.c \
		./parsing/parse_colors.c \
		./parsing/init_game.c \
		./parsing/texture.c \
		./rendering/rendering.c \
		./raycasting/player.c
OBJS = $(SRCS:%.c=%.o)
all: $(NAME)
$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDE)
clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
.PHONY:	all bonus clean fclean re
