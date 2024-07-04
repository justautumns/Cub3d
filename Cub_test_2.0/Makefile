NAME = cub
CC = cc -Wall -Wextra -Werror

SOURCES = cub.c movement.c draw.c utils.c

OBJECTS = ${SOURCES:.c=.o}

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) -L ./mlx -lmlx -lXext -lX11 -lm -lz -L/usr/include -Imlx

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS) $(NAME)

re: fclean all
