CFLAGS := -Wall -Wextra -Werror -Werror=vla
NAME := libftprintf.a
AR := ar
RM = rm -f
CC = cc
libs := libft
h_files := ft_printf.h
obj_files := ft_printf.o

all: $(NAME)

$(NAME): $(obj_files) | $(libs)
	$(AR) -rcs $@ $?

$(obj_files):%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(libs):
	make -C $@

clean:
	$(RM) $(obj_files)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: all

redebug: CFLAGS += -g
redebug: re

.PHONY: all clean fclean re debug redebug
