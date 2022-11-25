#include "get_next_line.h"

char	*get_next_line(int fd)
{

    return (line);
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
}
