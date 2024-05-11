CC := gcc
CFLAGS := -Wall -Wextra -Werror
CINCLUDES := -Iinclude -Ilibft
CLIBS := -Llibft -lft

SRC_FILES := $(wildcard src/*.c) $(wildcard src/**/*.c)
OBJ_FILES := $(subst .c,.o,$(SRC_FILES))

NAME := so_long

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^ $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJ_FILES)

fclean:
	rm -f $(NAME)
