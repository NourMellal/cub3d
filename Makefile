Name=Cub3d
SRC= ./parsing/main.c ./parsing/gnl.c  ./parsing/spilts.c ./parsing/utilsparsing.c ./parsing/charsinmap.c ./parsing/split2.c
all: $(Name)
$(Name) : $(SRC)
	cc -Wall -Wextra -Werror -o $(Name) $(SRC) -g3  
clean:

fclean: 
	rm -f $(Name)
re: fclean all