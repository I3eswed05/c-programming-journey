NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC     = main.c so_long_utils.c map_validation.c GUI_1.c\
		check_paths.c get_next_line.c get_next_line_utils.c GUI_2.c\
		Move.c putnbr.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

# %.o: %.c so_long.h
# 	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
