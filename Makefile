NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

SRC = main.c op_push.c op_swap.c op_rotate.c op_reversed_rotate.c \
		disorder.c input.c simple_alg.c stack_utils.c rank.c medium_alg.c \
		complex_alg.c adaptive_alg.c bench.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re