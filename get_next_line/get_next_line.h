#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H\

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE    
# define BUFFER_SIZE 5
# endif

typedef struct s_list
{
    char    *content;
    t_list  *next;
}           t_list;

char	*get_next_line(int fd);
void    read_and_stach(int fb, char *);

#endif
