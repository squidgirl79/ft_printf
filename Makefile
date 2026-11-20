NAME=libftprintf.a

CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	ar -r $(NAME)

clean:

fclean:

re:

.PHONY: all, clean, fclean, re
