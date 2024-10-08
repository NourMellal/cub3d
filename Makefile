.PHONY: all clean fclean re

NAME := Cub3d

DIR_MLX := ./minilibx-linux/
MLX := $(DIR_MLX)libmlx.a

INCLUDE := ./include/
DIR_SRC := ./src/
OBJ_DIR := ./obj/

PARSING := $(DIR_SRC)parsing/
PARSING_INC := $(INCLUDE)/parsing.h
PARSING_SRC := $(PARSING)charsinmap.c $(PARSING)gnl.c $(PARSING)main.c \
				$(PARSING)splits.c $(PARSING)split2.c $(PARSING)utilsparsing.c
PARSING_OBJS := $(PARSING_SRC:.c=.o)
PARSING_OBJS := $(patsubst $(DIR_SRC)%, $(OBJ_DIR)%, $(PARSING_OBJS))

RAYCASTING := $(DIR_SRC)ray-casting/
RAYCASTING_INC := $(INCLUDE)/raycasting.h
RAYCASTING_SRC := $(RAYCASTING)raycasting.c $(RAYCASTING)player.c $(RAYCASTING)draw2Dmap.c \
					$(RAYCASTING)mlx_utils.c
RAYCASTING_OBJS := $(RAYCASTING_SRC:.c=.o)
RAYCASTING_OBJS := $(patsubst $(DIR_SRC)%, $(OBJ_DIR)%, $(RAYCASTING_OBJS))

VEC2 := $(DIR_SRC)vec2/
VEC2_INC := $(INCLUDE)/vec2.h
VEC2_SRC := $(VEC2)vec2.c
VEC2_OBJS := $(VEC2_SRC:.c=.o)
VEC2_OBJS := $(patsubst $(DIR_SRC)%, $(OBJ_DIR)%, $(VEC2_OBJS))


LIBFT_DIR := ./lib/libft
LIBFT := $(LIBFT_DIR)/libft.a
CC := cc
CFLAGS := -fsanitize=address -g3 -Wall -Wextra -Werror
MLXFLAGS := -L $(DIR_MLX) -lmlx -lXext -lX11 -lm
CI := -I $(DIR_MLX) -I $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/parsing
	mkdir -p $(OBJ_DIR)/ray-casting
	mkdir -p $(OBJ_DIR)/vec2


$(OBJ_DIR)%.o: $(DIR_SRC)%.c
	$(CC) $(CFLAGS) $(CI) -c $< -o $@

$(NAME): $(OBJ_DIR) $(PARSING_OBJS) $(RAYCASTING_OBJS) $(VEC2_OBJS) $(LIBFT)
	$(CC) $(CI) $(CFLAGS) $(PARSING_OBJS) $(RAYCASTING_OBJS) $(VEC2_OBJS) -o $(NAME) $(LIBFT) $(MLX) $(MLXFLAGS)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all