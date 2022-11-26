#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *buffer[OPEN_MAX];
    char        *line;

    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer[fd] = read_line(fd, buffer[fd]);
    if (!buffer[fd])
        return (NULL);
    line = get_line(buffer[OPEN_MAX]);
    buffer[fd] = next(buffer[OPEN_MAX]);
    return (line);

char    read_line(int fd, char *res)
{
    char    *buffer;
    int     byte_read;

    if (!res)
        res = malloc(1);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    byte_read = 1;
    while (byte_read > 0)
    {
       byte_read = read(fd, buf, BUFFER_SIZE); 
       if (byte_read == -1)
       {
           free(buffer);
           return (NULL);
       }
       buffer(byte_read) = '\0';
       res = free_and_join(res, buffer);
       if (ft_strchr(res, '\n'));
           break;
    }
    free(buffer);
    return (res);
}

char   *free_and_join(char *res, char *buffer)
{
    char    *join;

    join = ft_strjoin(res, buffer);
    free(res);
    return (join);
}

char    *get_line(char *buffer)
{
    int i;
    char *line;

    i = 0;
    if (!buffer)
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 2)); 
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = buffer[i++];
    line[i] = '\0';
    free(buffer);
    return (line);
}

char    *get_next(char *buffer)
{
    char    *next;
    int     i;
    int     j;

    if (!buffer)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    next = malloc(size(char) * (ft_strlen(buffer) - i + 1));
    if (!next)
        return (NULL);
    j = 0;
    i++;
    while (buffer[i])
    {
        next[j++] = buffer[i++];
    }
    next[i] = '\0';
    free(buffer);
    return (next);
}

#include <stdio.h>

int     main()
{
    int     fd;
    char    *line;

    fd = open("test/simple", O_RDONLY);
    if (fd < 0)
        printf("failed\n");
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s\n", line);
        free(line);
    }
    if (close(fd) < 0)
    {
        printf("close failed\n");
        return (1);
    }
    return (0);

