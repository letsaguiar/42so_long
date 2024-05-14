CC := gcc
CFLAGS := -Wall -Wextra -Werror
CINCLUDES := -Iinclude -Ilibft
CLIBS := -lmlx -lX11 -lXext -Llibft -lft

SRC_FILES := $(wildcard src/*.c) $(wildcard src/**/*.c)

NAME := so_long

all: $(NAME)

$(NAME): $(SRC_FILES)
	make -C libft
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(CLIBS)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
