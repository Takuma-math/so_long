NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_INC = -I./mlx
MLX_LIB = -L./mlx -lmlx -framework OpenGL -framework AppKit
SRC = src/main.c
OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LIB)
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
