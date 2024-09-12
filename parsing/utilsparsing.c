#include "header.h"
int isallspace(char *line)
{
    int i;
    i = 0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '\t')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void initdata()
{
    int i;
    i = 0;
    while(i < data()->lines)
    {
        data()->map[i] = NULL;
        i++;
    }
}

int checkmap(char *line)
{
    char **split;
    
    return 5;
}

int freeall()
{
    int i;
    i = 0;
    while(i < data()->lines)
    {
        free(data()->map[i]);
        i++;
    }
    free(data()->map);
    return 0;
}