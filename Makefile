NAME = so_long.a

CC = clang

FLAGS = -Wall -Wextra -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

LIB = -Lmlx -lmlx -Imlx -lXext -lX11

all: $(NAME)
	$(CC) $(FLAGS) $(NAME) $(LIB) -o so_long && ./so_long

$(NAME): $(OBJ)
	ar -rs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
