/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:27:44 by ori               #+#    #+#             */
/*   Updated: 2019/01/28 17:14:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	usage(void)
{
	ft_printf("{cyan}Usage: ft_ssl command [command opts] [command args]{}\n");
	ft_error(NULL);
}

static int	flag_handle(char *cmd)
{
	if (!ft_strcmp("-p", cmd))
		g_sslf[0] = true;
	else if (!ft_strcmp("-q", cmd))
		g_sslf[1] = true;
	else if (!ft_strcmp("-r", cmd))
		g_sslf[2] = true;
	else if (!ft_strcmp("-s", cmd))
		g_sslf[3] = true;
	else if (!ft_strcmp("-n", cmd))
		g_sslf[4] = true;
	else
		return (0);
	if (g_sslf[0])
		return (0);
	return (1);
}

static void	handle(char *cmd, char *args)
{
	if (!g_sslf[3] && !g_sslf[5] && flag_handle(args))
		return ;
	else if (g_sslf[0] && !g_sslf[5])
		stdinhandle(cmd);
	else if (g_sslf[3] && !g_sslf[5])
		cmdhandle(cmd, args, NULL);
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
	{
		handle(av[1], av[i]);
		if (g_sslf[3] && i + 1 == ac)
		{
			ft_printf("{bold_red}%s: option requires and ", av[1]);
			ft_printf("argument -- s{}\n");
			usage();
		}
	}
}
