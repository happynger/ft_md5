/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:26:32 by ori               #+#    #+#             */
/*   Updated: 2019/01/25 13:22:25 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <fcntl.h>
#include <unistd.h>

/*
**	Usage: ./ft_ssl command [options] [args]
*/

static t_ehash	get_ehash(char *str)
{
	if (!ft_strcmp("md5", str))
		return (md5);
	else if (!ft_strcmp("sha256", str))
		return (sha256);
	return (null);
}

void			stdinhandle(char *cmd)
{
	int			fd;

	fd = 0;
	(void)cmd;
}

void			filehandle(char *cmd, char *name)
{
	int			fd;
	int			i[2];
	char		buff[BUFF_SIZE];
	char		*msg;

	if ((fd = open(name, O_RDONLY)) <= 2)
		print_efile(name, cmd);
	i[1] = 0;
	while ((i[0] = read(fd, buff, BUFF_SIZE)) > 0)
		i[1] += i[0];
	close(fd);
	if ((fd = open(name, O_RDONLY)) <= 2)
		print_efile(name, cmd);
	msg = ft_memalloc(i[1] + 20);
	i[1] = 0;
	while((i[0] = read(fd, buff, BUFF_SIZE)) > 0)
	{
		ft_memcpy(msg + i[1], buff, i[0]);
		i[1] += i[0];
	}
	cmdhandle(cmd, msg);
	ft_strdel(&msg);
}

void			cmdhandle(char *cmd, char *args)
{
	int			i;
	bool		handle;
	uint64_t	*tmp;

	i = 0;
	handle = false;
	while (g_lookup[i].name != NULL)
	{
		if (!ft_strcmp(g_lookup[i].name, cmd))
		{
			tmp = g_lookup[i].func((uint8_t *)args, ft_strlen(args));
			print_handler(get_ehash(cmd), args, tmp);
			handle = true;
			break ;
		}
		i++;
	}
	if (!handle)
		print_error(cmd);
}
