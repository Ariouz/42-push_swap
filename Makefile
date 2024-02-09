NAME= push_swap

FLAGS= -Wall -Werror -Wextra

LIBFT_DIR= libs/libft
LIBFT_A= $(LIBFT_DIR)/libft.a

SRCS= push_swap.c \
stack.c \
stack_operation.c

OBJS = $(SRCS:.c=.o)

$(NAME): libft $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I.

test:
	make $(NAME)
	./$(NAME) 5 8 4 3 1 7

all:
	make $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean BONUS=1

fclean:
	make clean
	make -C $(LIBFT_DIR) fclean BONUS=1
	rm -rf $(NAME)

re:
	make fclean
	make all

libft:
	make -C $(LIBFT_DIR) bonus

.PHONY: all fclean clean re libft