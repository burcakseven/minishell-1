/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:30:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 00:19:29 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

char	*add_symbol(void)
{
	char	*cwd;
	char	*added;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	added = ft_strjoin(cwd, "/");
	return (added);
}

void	set_std_file(int in_fd, int out_fd)
{
	int	ret;

	ret = 0;
	if (in_fd >= 0)
	{
		if (dup2(in_fd, STDIN_FILENO) == -2)
			ret = -1;
	}
	if (out_fd >= 0)
	{
		if (dup2(out_fd, STDOUT_FILENO) == -2)
			ret = -1;
	}
	if (ret == -1)
		exit (1);
}

void	assign_in_out_1(char *edit_param, char *symbol, char *redir_param)
{
	(void) redir_param;
	if (g_data->out_fd >= 0)
		close(g_data->out_fd);
	if (macrocomp(">>", symbol))
		g_data->out_fd = open(edit_param, O_WRONLY \
		| O_CREAT | O_APPEND, 0777);
	else
		g_data->out_fd = open(edit_param, O_WRONLY \
		| O_CREAT | O_TRUNC, 0777);
	if (g_data->out_fd < 0)
		exit(1);
}

void	assign_in_out(char *edited_param, char *symbol, char *redir_param)
{
	char	*path;
	char	*itoas;

	itoas = ft_itoa(g_data->i);
	path = ft_strjoin("includes/heredoc", itoas);
	if (!ft_strncmp("<", symbol, 1))
	{
		if (g_data->in_fd >= 0)
			close(g_data->in_fd);
		if (macrocomp("<<", symbol))
			g_data->in_fd = open(path, O_RDONLY, 0777);
		else
			g_data->in_fd = open(edited_param, O_RDONLY, 0777);
		if (g_data->in_fd < 0)
		{
			printf("%s: No such file or directory\n", redir_param);
			g_data->_redirection->redir_control = 0;
		}
	}
	else
		assign_in_out_1(edited_param, symbol, redir_param);
	free(path);
	free(itoas);
}
