NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_INC = -I./mlx
MLX_LIB = -L./mlx -lmlx -framework OpenGL -framework AppKit
SRC = src/main.c src/map_parser.c src/map_shape_validator.c src/map_element_validator.c \
	src/map_validator.c src/map_playable_validator.c
OBJ = $(SRC:.c=.o)
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_LIB)

$(LIBFT):
	@make -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
