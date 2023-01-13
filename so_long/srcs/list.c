/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:11:55 by dly               #+#    #+#             */
/*   Updated: 2023/01/11 16:42:26by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		exit_msg_err("malloc map");
	(*map)->map = NULL;
}

t_elem	*new_node(char *str)
{
	t_elem	*ptr;

	ptr = (t_elem *)malloc(sizeof(t_elem));
	if (!ptr)
		return (NULL);
	ptr->line = str;
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->idx = 0;
	return (ptr);
}

t_elem	*last_node(t_map *m)
{
	t_elem	*tmp;

	tmp = m->map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_node_back(t_map **m, t_elem *node)
{
	t_elem	*tmp;

	if (!m || !node)
		return ;
	if ((*m)->map)
	{
		tmp = last_node(m);
		tmp->next 
		last = (*map)->last;
		(*stack)->last->next = *node;
		(*node)->prev = last;
		(*stack)->last = *node;
	}
	else
	{
		(*stack)->first = *node;
		(*u)->last = *node;
	}
	(*stack)->length++;
}