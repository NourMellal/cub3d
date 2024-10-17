# SRCS


LIBFT		= $(wildcard lib/*/*.c)

SRC_m		= $(wildcard src/*/*.c)
OBJ_m		= $(SRC_m:.c=.o) $(LIBFT:.c=.o)



# VARS
CC = cc
NAME = cub3d
NAME_b = miniRT_bonus
NAME_e = miniRT_extra
CFLAGS = -Iinclude -Ilib #ß -Wall -Wextra -Werror -O3
LDFLAGS = -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm

ifeq ($(shell uname -s),Darwin)
	CFLAGS += -DINPUT_MAC
	LDFLAGS = -L. -lmlx -framework OpenGL -framework AppKit
endif

.PHONY : re reb ree fclean clean all bonus extra
.SECONDARY : ${OBJ_m}

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@

all : ${NAME}

clean :
	rm -f ${OBJ_m}

fclean : clean
	rm -f $(NAME)


${NAME}: $(OBJ_m)
	$(CC) $(CFLAGS) $(OBJ_m) -o $(NAME) $(LDFLAGS)

re : fclean all
