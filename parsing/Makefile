Name=Cub3d
SRC= main.c gnl.c spilts.c utilsparsing.c charsinmap.c split2.c
all: $(Name)
$(Name) : $(SRC)
	cc -Wall -Wextra -Werror -o $(Name) $(SRC) -g3 -fsanitize=address 
clean:

fclean: 
	rm -f $(Name)
re: fclean all