/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:10:15 by dly               #+#    #+#             */
/*   Updated: 2023/01/31 16:47:37 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

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