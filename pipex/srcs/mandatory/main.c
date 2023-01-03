/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:23:48 by dly               #+#    #+#             */
/*   Updated: 2023/01/03 19:08:23 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	p_err(char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	return (1);
}

void	p_err_()
{
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	(void)ac;
	(void)av;
	
	if (ac != 5)
		return (0);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		return (p_err("err\n"));
	pipex.outfile = open(av[3], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		return (p_err("err\n"));
	pipex.envp_path = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.envp_path, ':');
	if (pipe(pipex.end) < 0)
		return (p_err);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
			
	}
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
	{
		
	}
	if (close(pipex.infile) < 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
