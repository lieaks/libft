/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:23:48 by dly               #+#    #+#             */
/*   Updated: 2023/01/04 20:03:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_err_(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipe(t_pipex *pipex)
{
	if (close(pipex->end[0]) || close(pipex->end[1]))
		p_err_("ERR_CLOSE");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	(void)ac;
	(void)av;
	
	if (ac != 5)
		return (1);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		p_err_("ERR_OPEN");
	pipex.outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		p_err_("ERR_OPEN");
	pipex.envp_path = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.envp_path, ':');
	if (pipex.cmd_paths == NULL)
		p_err_("ERR_MALLOC");
	if (pipe(pipex.end) < 0)
	{
		free_parent(&pipex);
		p_err_("ERR_PIPE");
	}
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		child_one(pipex, av, envp);
	pipex.child2 = fork();
	if (pipex.child2 == 0)
		child_two(pipex, av, envp);
	close_pipe(&pipex);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
