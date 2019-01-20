/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:26:32 by ori               #+#    #+#             */
/*   Updated: 2019/01/20 14:24:55 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

/*
**	
**	Usage: ./ft_ssl command [options] [args]
**	
*/

void	cmdhandle(char *cmd, char *args)
{
	int		i;
	char	*ret;

	i = 0;
	while (i < TABLE)
	{
		if (!ft_strcmp(g_lookup[i].name, cmd))
		{
			ft_printf("%s\n", (ret = g_lookup[i].func(args, ft_strlen(args))));
			ft_strdel(&ret);
			break ;
		}
		i++;
	}
}
