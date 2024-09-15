#ifndef HEADER_H
#define HEADER_H
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *get_next_line(int fd);
// map color index 0 for floor 1 for sky
struct s_parse
{
    char **file;
    int fd;
    int lines;
    char *elemets[6];
    char direction;
    int mapcolor[2][3];
   int texture[4];
};
typedef struct s_parse t_parse;
char	**ft_split(char *str);
char	**ft_splitV(char *str);
t_parse *data();
int isallspace(char *line);
void initdata();
int freefile(char **tofree);
int freeelement();
int checkmap(char *line);
void charsinmap();
#endif