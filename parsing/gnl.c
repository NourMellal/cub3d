#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
char *get_next_line(int fd)
{
    int     byte;
    char    c;
    char    *str_buffer;
    int     i;

    if (fd < 0)
        return (NULL);
    i = 0;
    str_buffer = (char *)malloc(10000000);
    if (!str_buffer)
        return (NULL);
    byte = read(fd, &c, 1); 
    while (byte > 0)
    {
        str_buffer[i] = c;
        i++;
        if(c == '\n' || c == EOF)
            break ;
        byte = read(fd, &c, 1); 
    }
    if (i == 0 || byte < 0)
    {
        free(str_buffer);
        return (NULL);
    }
    str_buffer[i] = '\0';
    return (str_buffer);
}