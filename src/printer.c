/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:38:57 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/25 13:43:28 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print_sha256(char *input, uint64_t *output)
{
	int		i;

	if (!g_sslflags[4] && !g_sslflags[1] && !g_sslflags[2])
		ft_printf("{blue}SHA256 ({magenta}\"%s\"{blue}){} = {bold_red}", input);
	else if (!g_sslflags[1] && g_sslflags[4] && !g_sslflags[2])
		ft_printf("SHA256 (\"%s\") = ", input);
	else if ((g_sslflags[1] || g_sslflags[2]) && !g_sslflags[4])
		ft_printf("{bold_red}");
	i = -1;
	while (++i < 8)
		ft_printf("%0x", output[i]);
	if (g_sslflags[2] && !g_sslflags[4] && !g_sslflags[1])
		ft_printf(" {magenta}%s", input);
	else if (g_sslflags[2] && g_sslflags[4] && !g_sslflags[1])
		ft_printf(" %s", input);
	if (!g_sslflags[4])
		ft_printf("{}\n");
	else
		ft_printf("\n");
}

static void		print_md5_help(uint64_t *output)
{
	int		i;
	int		j;
	t_wb	wb;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		wb.w = output[i];
		while (++j < 4)
			ft_printf("%02x", wb.b[j]);
	}
}

static void		print_md5(char *input, uint64_t *output)
{
	if (!g_sslflags[4] && !g_sslflags[1] && !g_sslflags[2])
		ft_printf("{blue}MD5 ({magenta}\"%s\"{blue}){} = {bold_red}", input);
	else if (!g_sslflags[1] && g_sslflags[4] && !g_sslflags[2])
		ft_printf("MD5 (\"%s\") = ", input);
	else if ((g_sslflags[1] || g_sslflags[2]) && !g_sslflags[4])
		ft_printf("{bold_red}");
	print_md5_help(output);
	if (g_sslflags[2] && !g_sslflags[4] && !g_sslflags[1])
		ft_printf(" {magenta}%s", input);
	else if (g_sslflags[2] && g_sslflags[4] && !g_sslflags[1])
		ft_printf(" %s", input);
	if (!g_sslflags[4])
		ft_printf("{}\n");
	else
		ft_printf("\n");
}

void			print_error(char *in)
{
	if (!g_sslflags[4])
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
}

void			print_efile(char *name, char *cmd)
{
	if (!g_sslflags[4])
	{
		ft_printf("{bold_red}ft_ssl: %s: File ('%s')", cmd, name);
		ft_printf(" doesn't exist or is a directory{}\n");
	}
	else
	{
		ft_printf("ft_ssl: %s: File ('%s')", cmd, name);
		ft_printf(" doesn't exist or is a directory\n");
	}
}

void			print_handler(t_ehash hash, char *input, uint64_t *output)
{
	if (hash == md5 && output != NULL)
		print_md5(input, output);
	else if (hash == sha256 && output != NULL)
		print_sha256(input, output);
	else
		print_error(input);
}
