/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:47:04 by dly               #+#    #+#             */
/*   Updated: 2023/01/03 19:15:18 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.end[1], 1);
	close(pipex.end[0]);
	if (close < 0)
	{
		// free
	}
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(av, ' ');
	pipex.cmd = pipex.cmd_args[0];

	
	execve(pipex.cmd, pipex.cmd_args ,envp);
}