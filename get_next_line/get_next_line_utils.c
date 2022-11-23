#include "get_next_line.h"

void    read_and_stach(int fd, t_list *stash, size_t *readed_ptr)
{
    char *buffer;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return ;
    while (!found_newline(stash) && *readed_ptr != 0)
    {
        *readed_ptr = read(fd, buffer, BUFFER_SIZE);
        buffer[*readed_ptr] = '\0'; 
    }

}

/* Looks for a '\n' in the given linked list. */
int found_newline(t_list *stash)
{
    int     i;
    t_list  *current;

    if (stash == NULL)
        return (0);
    current = lst_get_last(stash);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

/* Return a ptr to the last node in our stash */
char *lst_get_last(t_list *stash)
{
    t_list  *current;

    current = stash;
    while (current && current->next)
        current = current->next;
    return (current);
}
