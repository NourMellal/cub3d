.PHONY: all clean fclean re


NAME = Cub3d

MLX = $(DIR_MLX)libmlx.a
DIR_MLX = ./minilibx-linux/

INCLUDE = ./include/

DIR_SRC = ./src/


PARSING = $(DIR_SRC)parsing/

PARSING_INC = $(INCLUDE)/parsing.h

PARSING_SRC = $(PARSING)charsinmap.c $(PARSING)gnl.c $(PARSING)main.c \
				$(PARSING)splits.c $(PARSING)split2.c $(PARSING)utilsparsing.c

PARSING_OBJS = $(PARSING_SRC:.c=.o)


RAYCASTING = $(DIR_SRC)ray-casting/

RAYCASTING_INC = $(INCLUDE)/raycasting.h

RAYCASTING_SRC = $(RAYCASTING)raycasting.c

RAYCASTING_OBJS = $(RAYCASTING_SRC:.c=.o)
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -L $(DIR_MLX) -lmlx -lXext -lX11 -lm
CI = -I $(DIR_MLX) -I $(INCLUDE)

$(NAME) :  $(PARSING_OBJS) $(RAYCASTING_OBJS) $(LIBFT)
	$(CC) $(CI) $(CFLAGS) $(PARSING_OBJS) $(RAYCASTING_OBJS) -o $(NAME) $(LIBFT) $(MLX) $(MLXFLAGS)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(PARSING_OBJS) $(RAYCASTING_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.SECONDARY: $(PARSING_OBJS) $(RAYCASTING_OBJS)
