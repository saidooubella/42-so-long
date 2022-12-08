
CC=cc
FLAGS=-Wall -Wextra -Werror
MLX_FLAGS=-lmlx -framework OpenGL -framework AppKit
NAME=so_long

INCLUDES=bonus/ft_printf.h bonus/get_next_line.h bonus/so_long.h bonus/so_long_init.h \
bonus/stack.h bonus/string_utils.h bonus/utils.h mandatory/ft_printf.h mandatory/get_next_line.h \
mandatory/so_long.h mandatory/so_long_init.h mandatory/stack.h mandatory/string_utils.h mandatory/utils.h

MANADATORY_SRCS=mandatory/ft_char_print_utils.c mandatory/ft_number_print_utils.c mandatory/ft_printf.c \
mandatory/get_next_line.c mandatory/get_next_line_utils.c mandatory/so_long.c mandatory/so_long_.c \
mandatory/so_long__.c mandatory/so_long___.c mandatory/so_long____.c mandatory/so_long______.c \
mandatory/so_long_______.c mandatory/so_long________.c mandatory/so_long_________.c \
mandatory/so_long_init.c mandatory/stack.c mandatory/stack_.c mandatory/string_utils.c \
mandatory/string_utils_.c mandatory/utils.c mandatory/utils_.c

BONUS_SRCS=bonus/ft_char_print_utils.c bonus/ft_number_print_utils.c bonus/ft_printf.c \
bonus/get_next_line.c bonus/get_next_line_utils.c bonus/so_long.c bonus/so_long_.c bonus/so_long__.c \
bonus/so_long___.c bonus/so_long____.c bonus/so_long_____.c bonus/so_long______.c bonus/so_long_______.c \
bonus/so_long________.c bonus/so_long_________.c bonus/so_long_init.c bonus/so_long_init_.c bonus/so_long_init__.c \
bonus/so_long_init___.c bonus/so_long_init____.c bonus/stack.c bonus/stack_.c bonus/string_utils.c bonus/string_utils_.c \
bonus/utils.c bonus/utils_.c

MANADATORY_OBJS=$(MANADATORY_SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

$(NAME): $(MANADATORY_OBJS)
	$(CC) $(MLX_FLAGS) $^ -o $@

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(MLX_FLAGS) $^ -o $(NAME)

clean:
	rm -rf $(MANADATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
