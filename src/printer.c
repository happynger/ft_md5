/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:38:57 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/28 17:16:09 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print_sha256(char *input, uint64_t *output)
{
	int		i;

	if (!g_sslf[4] && !g_sslf[1] && !g_sslf[2] && g_sslf[3])
		ft_printf("{blue}SHA256 ({magenta}\"%s\"{blue}){} = {red}", input);
	else if (!g_sslf[4] && !g_sslf[1] && !g_sslf[2] && !g_sslf[3])
		ft_printf("{blue}SHA256 ({magenta}%s{blue}){} = {red}", input);
	else if (!g_sslf[1] && g_sslf[4] && !g_sslf[2] && g_sslf[3])
		ft_printf("SHA256 (\"%s\") = ", input);
	else if (!g_sslf[1] && g_sslf[4] && !g_sslf[2] && !g_sslf[3])
		ft_printf("SHA256 (%s) = ", input);
	else if ((g_sslf[1] || g_sslf[2]) && !g_sslf[4])
		ft_printf("{red}");
	i = -1;
	while (++i < 8)
		ft_printf("%0x", output[i]);
	if (g_sslf[2] && !g_sslf[4] && !g_sslf[1])
		ft_printf(" {magenta}%s", input);
	else if (g_sslf[2] && g_sslf[4] && !g_sslf[1])
		ft_printf(" %s", input);
	if (!g_sslf[4])
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

void			print_stdin(char *input, uint64_t *output, t_ehash hash)
{
	int		i;

	ft_printf("%s", input);
	if (hash == md5)
		print_md5_help(output);
	else if (hash == sha256)
	{
		i = -1;
		while (++i < 8)
			ft_printf("%0x", output[i]);
	}
	ft_printf("\n");
}

static void		print_md5(char *input, uint64_t *output)
{
	if (!g_sslf[4] && !g_sslf[1] && !g_sslf[2] && g_sslf[3])
		ft_printf("{blue}MD5 ({magenta}\"%s\"{blue}){} = {red}", input);
	else if (!g_sslf[4] && !g_sslf[1] && !g_sslf[2] && !g_sslf[3])
		ft_printf("{blue}MD5 ({magenta}%s{blue}){} = {red}", input);
	else if (!g_sslf[1] && g_sslf[4] && !g_sslf[2] && g_sslf[3])
		ft_printf("MD5 (\"%s\") = ", input);
	else if (!g_sslf[1] && g_sslf[4] && !g_sslf[2] && !g_sslf[3])
		ft_printf("MD5 (%s) = ", input);
	else if ((g_sslf[1] || g_sslf[2]) && !g_sslf[4])
		ft_printf("{red}");
	print_md5_help(output);
	if (g_sslf[2] && !g_sslf[4] && !g_sslf[1])
		ft_printf(" {magenta}%s", input);
	else if (g_sslf[2] && g_sslf[4] && !g_sslf[1])
		ft_printf(" %s", input);
	if (!g_sslf[4])
		ft_printf("{}\n");
	else
		ft_printf("\n");
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
