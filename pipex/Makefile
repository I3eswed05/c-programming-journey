NAME        := pipex

SRC_DIR     := src
INC_DIR     := include
LIBFT_DIR   := libft

SRC         := $(wildcard $(SRC_DIR)/*.c)
OBJ         := $(SRC:%.c=%.o)

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3
INCLUDES    := -I$(INC_DIR) -I$(LIBFT_DIR)

LIBFT_A     := $(LIBFT_DIR)/libft.a
LIBS        := -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
