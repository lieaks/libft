#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static t_list   *stash = NULL;
    char            *line;
    size_t          readed;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &linem 0) <= 0)
        return (NULL);
    readed = 1;
    line = NULL;
    // 1. read from fd and add to link list
    read_and_stach();
    // 2. extract stash to line 
    // 3. clean up stash

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
