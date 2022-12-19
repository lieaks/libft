/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:22 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 20:38:18 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

elem	*new_node(int nb)
{
	elem	*ptr;

	ptr = (elem *)malloc(sizeof(elem));
	if (!ptr)
		return (NULL);
	ptr->num = nb;
	ptr->index = 0;
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->link = NULL;
	return (ptr);
}
