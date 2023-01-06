/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:59:57 by dly               #+#    #+#             */
/*   Updated: 2023/01/06 17:19:12 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	get_infile(char **av, t_pipexb *pipex)
{
	if (pipex->here_doc)
		here_doc(av[2], pipex);
	else
	{
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile == -1)
			exit_msg_err(ERR_FILES);
	}
}

void	get_outfile(char *av_last, t_pipexb *pipex)
{
	pipex->outfile = open(av_last, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
			exit_msg_err("Outfile");
}
