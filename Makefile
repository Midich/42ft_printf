CFLAGS		:= -Wall -Wextra -Werror -Werror=vla
NAME		:= libftprintf.a
AR			:= ar
RM			:= rm -f
CC			:= cc
libft_path	:= libft
libft		:= $(libft_path)/libft.a
h_files		:= ft_printf.h
obj_files	:= ft_printf.o ft_handler.o ft_parser.o ft_print_character.o \
			   ft_print_integer.o ft_print_string.o	ft_print_unsigned.o	\
			   ft_formaters.o ft_util.o ft_print_hex.o

all: $(NAME)

$(NAME): $(obj_files) $(libft)
	cp $(libft) $@
	$(AR) -rcs $@ $(obj_files)

$(obj_files):%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(libft):
	make -C $(libft_path)

clean:
	make -C $(libft_path) clean
	$(RM) $(obj_files)

fclean: clean
	make -C $(libft_path) fclean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: all

redebug: CFLAGS += -g
redebug: re

.PHONY: all clean fclean re debug redebug
