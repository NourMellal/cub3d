#include "header.h"
int isallspace(char *line)
{
    int i;
    i = 0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
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
        data()->file[i] = NULL;
        i++;
    }
}
void charscheck(char *element,char **split)
{
        if(strcmp(element,"NO") && strcmp(element,"SO") &&\
         strcmp(element,"WE") && strcmp(element,"EA") && \
         strcmp(element,"C") && strcmp(element,"F"))
        {
            printf("Error\nin map2");
            exit(freefile(split)+freeelement());
        }

}
int checkmap(char *line)
{
   static int index = 0;
    char **split;
    int i =0;
    split = ft_split(line);
    if(!split)
        return 0;
    if(index <  6)
    {
        if(split[1] == NULL)
            exit(freefile(split)+printf("Error\nin map1\n")+freeelement());
        charscheck(split[0],split);
        data()->elemets[index] = strdup(line);
    }       while(split[i])
        {
            free(split[i]);
            i++;
        }
        free(split);
        if(index == 6)
        {
            return 1;
        }
        index++;
    return 5;
}

int freefile(char **tofree)
{
    int i;
    
    i = 0;
    while(i < data()->lines)
    {
        free(data()->file[i]);
        i++;
    }
    free(data()->file);
    if(tofree == NULL)
        return 0;
    else
    {
        i = 0;
        while(tofree[i])
        {
            free(tofree[i]);
            i++;
        }
        free(tofree);
    }
    return 0;
}