/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:14 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/28 18:03:17 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <errno.h>
#include <string.h>

void			print_error(char *in)
{
	if (!g_sslf[4])
	{
		ft_printf("{cyan}ft_ssl: {red}Error: '{bold_red}%s{red}'", in);
		ft_printf(" is an invalid command");
		ft_printf(".{}\n\n{bold_green}Standart commands:\n\n");
		ft_printf("Message Digest commands:\n{bold_magenta}md5\nsha256\n\n");
		ft_printf("{bold_green}Cipher commands:{}\n");
	}
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command", in);
		ft_printf(".\n\nStandart commands:\n\n");
		ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
		ft_printf("Cipher commands:\n");
	}
	ft_error(NULL);
}

int				print_efile(char *name, char *cmd)
{
	if (!g_sslf[4])
	{
		ft_printf("{magenta}ft_ssl: %s: File ('%s') ", cmd, name);
		ft_printf("{red}ERROR : {bold_red}%s{}\n", strerror(errno));
	}
	else
	{
		ft_printf("ft_ssl: %s: File ('%s') ", cmd, name);
		ft_printf("ERROR : %s\n", strerror(errno));
	}
	return (1);
}
