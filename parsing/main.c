#include "header.h"
t_parse *data()
{
    static struct s_parse data;
    return &data;
}
int countlines()
{
    char *line;
    int height = 0;
 line = get_next_line(data()->fd);
    if(!line)
    {
        return (write(2,"Error\nin file\n",15),-1);
    }
    while(line)
    {
        height++;
        free(line);
        line = get_next_line(data()->fd);
    }
    free(line);
    return height;
}
int stepone(char *av)
{
    
    int  (i);
    data()->fd = open(av,O_RDONLY);
    if(data()->fd == -1)
    {
        return write(2,"Error\nin file\n",15);
    }
    data()->lines= countlines();
    close(data()->fd);
    data()->fd = open(av,O_RDONLY);
    i = 0;
    if(data()->lines == -1)
    {
        return 0;
    }
    data()->map = (char **)malloc(sizeof(char *) * data()->lines);
    if(!data()->map)
    {
        return write(2,"Error\nin malloc\n",17);
    }
    initdata();
    
    while(i<data()->lines)
    {
        data()->map[i] = get_next_line(data()->fd);
        i++;
    }
    return 1;
};
int steptwo()
{
    int i = 0;
    while(i < data()->lines)
    {
       
       if(isallspace(data()->map[i]))
            i++;
        else
        {
           if(checkmap(data()->map[i]) == 0)
                 exit(freeall());
            i++;
        }    
    }
    return 1;
}
int main(int ac, char **av)
{
    if(ac != 2 ||strcmp(av[1]+strlen(av[1])-4,".cub"))
        return write(2,"Error\nin arguments\n",20);
    if(stepone(av[1]) == 0 )
        return 0;
    if(steptwo() ==0)
        return 0;
}