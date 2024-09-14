#include "header.h"
void freedouble(char **str)
{
    int i;
    i = 0;
    if(str)
    {
        while(str[i])
        {
            free(str[i]);
            i++;
        }
        free(str);
    }
}
void sameelemet()
{
int i =33;
int j =0;
char **str;
while(j < 6)
{
    str = ft_split(data()->elemets[j]);
    if(str)
    {
        if(strcmp(str[0],"NO") == 0)
            i-=3;
        else if(strcmp(str[0],"SO") == 0)
            i-=4;
        else if(strcmp(str[0],"WE") == 0)
            i-=5;
        else if(strcmp(str[0],"EA") == 0)
            i-=6;
        else if(strcmp(str[0],"F") == 0)
            i-=7;
        else if(strcmp(str[0],"C") == 0)
            i-=8;
    }
    freedouble(str);
    j++;
}
if(i != 0)
    exit(printf("Error\nmissing element")+freefile(NULL)+freeelement());
}
void issurrendbywalls()
{
    int i;
    int j;
    i = 0;
    while(i < data()->lines-1)
    {
        if(data()->file[i])
        {
            j = 0;
            while(data()->file[i][j])
            {
                if(data()->file[i][j] == '0' || data()->file[i][j] == 'N'\
                || data()->file[i][j] == 'S' || data()->file[i][j] == 'E'\
                || data()->file[i][j] == 'W')
                {
                    if( !data()->file[i-1] || !data()->file[i+1]\
                    ||data()->file[i][j+1] == ' ' || data()->file[i][j-1] == ' ' \
                    || data()->file[i+1][j] == ' ' || data()->file[i-1][j] == ' '\
                     || data()->file[i][j+1] == '\n' || data()->file[i][j-1] == '\n' \
                    || data()->file[i+1][j] == '\n' || data()->file[i-1][j] == '\n'\
                    )
                    {
                        printf("Error\nin map10\n");
                        exit(freefile(NULL)+freeelement());
                    }
                }
            j++;
            }
        }
        i++;
    }
    j = 0;
    while(data()->file[i][j])
    {
        if(data()->file[i][j] == '0' || data()->file[i][j] == 'N'\
        || data()->file[i][j] == 'S' || data()->file[i][j] == 'E'\
        || data()->file[i][j] == 'W')
        {
                printf("Error\nin map11\n");
                exit(freefile(NULL)+freeelement());
        }
        j++;
    }

}
void isdupchars()
{
    int i = 0;
    int j;
    int c;
    c =0;
    while(i < data()->lines)
    {
        if(data()->file[i])
        {
            j = 0;
            while(data()->file[i][j])
            {
                if(data()->file[i][j] == 'N' || data()->file[i][j] == 'S'\
                || data()->file[i][j] == 'E' || data()->file[i][j] == 'W')
                {
                    c++;
                    data()->direction = data()->file[i][j];
                    if(c > 1)
                    {
                        printf("Error\nin map12\n");
                        exit(freefile(NULL)+freeelement());
                    }
                }
                j++;
            }
        }
        i++;
    }
}
void charsinmap()
{
    int i;
    int j;
    i = 0;
    sameelemet();
    while(i < data()->lines)
    {
        if(data()->file[i])
        {
            j = 0;
            while(data()->file[i][j])
            {
                if(data()->file[i][j] != ' ' \
                && data()->file[i][j] != '1' && \
                data()->file[i][j] != '0' && \
                data()->file[i][j] != 'N' && \
                data()->file[i][j] != 'S' && \
                data()->file[i][j] != 'E' && \
                data()->file[i][j] != 'W' && \
                data()->file[i][j] != '\n')
                {
                    printf("Error\nin map3 %c --\n",data()->file[i][j]);
                    exit(freefile(NULL)+freeelement());
                }
                j++;
            }
        }
        i++;
    }
    issurrendbywalls();
    isdupchars();
}