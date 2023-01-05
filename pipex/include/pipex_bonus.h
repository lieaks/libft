/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:18 by dly               #+#    #+#             */
/*   Updated: 2023/01/05 18:10:08 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct s_pipexb
{
	pid_t	child;
	int		infile;
	int		outfile;
	int		*end;
	char	*cmd;
	char	*envp_path;
	char	**cmd_paths;
	char	**cmd_args;
	int		here_doc;
}	t_pipexb;


char	*get_path(char **envp);
/* libft */
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_join_three(char *str1, char *str2, char *str3);
// void	child_one(t_pipex pipex, char **av, char **envp);
// void	child_two(t_pipex pipex, char **av, char **envp);
// void	free_child(t_pipex *pipex, char *msg);
// void	free_parent(t_pipex *pipex);
// void	p_err_(char *msg);

#endif
