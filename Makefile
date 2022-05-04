NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lmlx -Lmlx -lft -Llibft -lm

LIBFT = libft/libft.a
LIBMLX = libmlx.dylib

SRC_DIR = ./src
INCLUDE_DIR = ./include

OBJ = utils.o \
	  parse_utils.o \
	  get_next_line.o \
	  parse.o \
	  transform.o \
	  draw_utils.o \
	  draw.o \
	  fdf.o

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $@

%.o : $(SRC_DIR)/%.c $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c -o $@ -I $(INCLUDE_DIR) $<

$(LIBFT) :
	$(MAKE) --directory=libft

$(LIBMLX) :
	$(MAKE) --directory=mlx
	cp mlx/libmlx.dylib .

clean :
	$(MAKE) --directory=libft clean
	-rm -f $(OBJ)

fclean : clean
	$(MAKE) --directory=libft fclean
	$(MAKE) --directory=mlx clean
	-rm -f libmlx.dylib
	-rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
