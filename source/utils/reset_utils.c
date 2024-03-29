/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 00:28:11 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	lexer_clear(t_lexer **lst, void (*del)(void*))
{
	t_lexer	*cnext;

	if (!lst || !del || !*lst)
		return ;
	cnext = (*lst);
	while (cnext != NULL)
	{
		cnext = (*lst)->next;
		(*del)((*lst)->str);
		free(*lst);
		(*lst) = cnext;
	}
}

void	reset_command_struct(t_bool flag)
{
	g_data->signal_select = DEFAULT;
	lexer_clear(&g_data->dvd_str->lexer, free);
	g_data->command_count = 0;
	free(g_data->line);
	free(g_data->pid);
	if (flag != TRUE)
		free_fd();
	_macro("VALUE_RESET");
	g_data->signal_select = 0;
}
