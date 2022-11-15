#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr->content = content;
	ptr->next = NULL;

}