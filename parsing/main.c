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
        return (printf("Error\nin file\n"),-1);
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
        return (printf("Error\nin file\n"),0);
    }
    data()->lines= countlines();
    close(data()->fd);
    data()->fd = open(av,O_RDONLY);
    i = 0;
    if(data()->lines == -1)
    {
        return 0;
    }
    data()->file = (char **)malloc(sizeof(char *) * data()->lines);
    if(!data()->file)
    {
        return (printf("Error\nin malloc\n"),0);
    }
    initdata();
    
    while(i<data()->lines)
    {
        data()->file[i] = get_next_line(data()->fd);
        i++;
    }
    return 1;
};
void steptwo()
{
    int i = 0;
    int j;
    while(i < data()->lines)
    {
        if(isallspace(data()->file[i]))
        {
            free(data()->file[i]);
            data()->file[i] = NULL;
        }
        i++;
    }
    i = 0;
    while(i < data()->lines)
    {
       if(data()->file[i])
            {
                j = checkmap(data()->file[i]);
                if(j == 0)
                    exit(freefile(NULL));
                else if (j == 1)
                    break;
                free(data()->file[i]);
                data()->file[i] = NULL;
            }    
                i++;
    }
}
int freeelement()
{
    int i = 0;
    while(i < 6)
    {
        free(data()->elemets[i]);
        i++;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac != 2 ||strcmp(av[1]+strlen(av[1])-4,".cub"))
        return printf("Error\nin args\n");
    if(stepone(av[1]) == 0 )
        return 0;
    steptwo();

    charsinmap();
    for(int i = 0; i < 6; i++)
    {
            printf("%s\n",data()->elemets[i]);
    }
    printf("------------------------empty line is replaced------------------------\n");
    for(int i = 0; i < data()->lines; i++)
    {
        if(data()->file[i])
            printf("%s",data()->file[i]);
    }
    puts("\n");
    return freefile(NULL)+freeelement();
}