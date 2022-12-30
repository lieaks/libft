/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:23:48 by dly               #+#    #+#             */
/*   Updated: 2022/12/30 14:19:12 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	p_err()
{
	write(2, "Err\n", 4);
	return (1);
}

void	p_err_()
{
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	
	if (ac != 5)
		return (0);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		return (p_err);
	pipex.outfile = open(av[3], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		return (p_err);
	pipex.envp_path = get_path();
	pipex.cmd_paths = ft_split(pipex.envp_path, ':');
	if (pipe(pipex.end) < 0)
		return (p_err);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		
	}
	if (close(pipex.infile) < 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
