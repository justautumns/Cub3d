NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
RM = rm -rf
INCLUDE = -I./libft -I./usr/include
SRCS =	main.c
OBJS = $(SRCS:%.c=%.o)
all: $(NAME)
$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
bonus: all

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
