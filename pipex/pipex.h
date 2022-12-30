/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:18 by dly               #+#    #+#             */
/*   Updated: 2022/12/30 14:11:43 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2; 
	int		infile;
	int		outfile;
	int		end[2];
	char	*cmd;
	char	*envp_path;
	char	**cmd_paths;
	char	**cmd_args;
}	t_pipex;

#endif
