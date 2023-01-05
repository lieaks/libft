/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:23:48 by dly               #+#    #+#             */
/*   Updated: 2023/01/05 18:10:43 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	p_err(char *msg)
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

void	close_pipe(t_pipexb *pipex)
{
	if (close(pipex->end[0]) || close(pipex->end[1]))
		p_err_("ERR_CLOSE");
}

int	right_args(char *av1, t_pipexb *pipex)
{
	if (av1 && !ft_strncmp(av1, "here_doc", 8))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	here_doc(char *av, t_pipexb *pipex)
{
	int	fd;
	
	fd = open(".heredoc_tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		p_err("Infile");
	else
	{
		get_next_line(STDIN_FILENO, 0);
	}
}

void	get_infile(char **av, t_pipexb *pipex)
{
	if (pipex->here_doc)
		here_doc(av[2], pipex);
	else
	{
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile == -1)
			p_err("Infile");
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipexb	pipex;
	
	if (ac < right_args(av[1], &pipex))
		return (write(2,"Invalid number of arguments.\n", 30), 1);
	get_infile(av, &pipex);
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
