/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:49:20 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 15:31:21 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int ac, char **av)
{
	t_info	rules;

	if (ac < 5 || ac > 6)
		return (write(2, "Use 5 or 6 args!\n", 18), 1);
	init_all(&rules, av);	
	simulation(&rules);
	free_all(&rules);
	return (0);
}
