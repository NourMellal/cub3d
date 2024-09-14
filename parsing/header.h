#ifndef HEADER_H
#define HEADER_H
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *get_next_line(int fd);
struct s_parse
{
    char **file;
    int fd;
    int lines;
    char *elemets[6];
    char direction;
    int maplines;
};
typedef struct s_parse t_parse;
char	**ft_split(char *str);
t_parse *data();
int isallspace(char *line);
void initdata();
int freefile(char **tofree);
int freeelement();
int checkmap(char *line);
void charsinmap();
#endif