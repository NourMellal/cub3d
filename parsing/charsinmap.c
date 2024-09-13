#include "header.h"
void sameelemet()
{

}
void charsinmap()
{
    int i;
    int j;
    i = 0;
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
                    exit(freeall(NULL));
                }
                j++;
            }
        }
        i++;
    }
}