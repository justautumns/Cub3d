NAME = cub3D
CC = cc -Wall -Wextra -Werror

SOURCES = cub.c movement.c draw.c utils.c movement_validation.c \
			rotations.c lines_check.c raycasting.c errorchecks.c \
			free_all.c getters.c init.c read_from_cub.c errorcheck2.c \
			errorcheck3.c key_press.c read_check_colors.c read_check_tex_path.c \
			read_check_utils.c read_check_colors1.c lines_check_utils.c \
			read_from_cub_utils.c

OBJECTS = ${SOURCES:.c=.o}

LIBFT = ./Libft/libft.a

INCLUDE = -I./libft -I./mlx

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./Libft
	$(MAKE) -C ./mlx
	$(CC) -o $(NAME) $(OBJECTS) $(LIBFT) -L ./mlx -lmlx -lXext -lX11 -lm -lz -L/usr/include -Imlx

%.o: %.c
	$(CC) $(INCLUDE) -c $< -o $@ 

clean:
	make -C ./Libft clean
	rm -f $(OBJECTS)

fclean:
	make -C ./Libft fclean
	rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
