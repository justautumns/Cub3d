NAME = cub
CC = cc -Wall -Wextra -Werror

SOURCES = cub.c movement.c draw.c utils.c movement_validation.c \
			rotations.c lines_check.c raycasting.c errorchecks.c

OBJECTS = ${SOURCES:.c=.o}

LIBFT = ./libft/libft.a

INCLUDE = INCLUDE = -I./libft

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	$(CC) $(LIBFT) -o $(NAME) $(OBJECTS) -L ./mlx -lmlx -lXext -lX11 -lm -lz -L/usr/include -Imlx

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
