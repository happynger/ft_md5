/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:27:44 by ori               #+#    #+#             */
/*   Updated: 2019/01/25 13:23:17 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	usage(void)
{
	ft_printf("{cyan}Usage: ft_ssl command [command opts] [command args]{}");
	ft_error("");
}

static int	flag_handle(char *cmd)
{
	if (!ft_strcmp("-p", cmd))
		g_sslflags[0] = true;
	else if (!ft_strcmp("-q", cmd))
		g_sslflags[1] = true;
	else if (!ft_strcmp("-r", cmd))
		g_sslflags[2] = true;
	else if (!ft_strcmp("-s", cmd))
		g_sslflags[3] = true;
	else if (!ft_strcmp("-n", cmd))
		g_sslflags[4] = true;
	else
		return (0);
	return (1);
}

static void	handle(char *cmd, char *args)
{
	if (flag_handle(args))
		return ;
	else if (g_sslflags[3])
		cmdhandle(cmd, args);
	else if (g_sslflags[0])
		stdinhandle(cmd);
	else
		filehandle(cmd, args);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac < 2)
		usage();
	set_glob();
	i = 1;
	while (++i < ac)
		handle(av[1], av[i]);
}
