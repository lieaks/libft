/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:18 by dly               #+#    #+#             */
/*   Updated: 2022/12/28 18:31:41 by dly              ###   ########.fr       */
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
	int		infile;
	int		outfile;
	int		end[2];
	char	*cmd;
	char	*envp_path;
	char	**my_paths;
	char	**cmd_args;
}	t_pipex;

#endif
