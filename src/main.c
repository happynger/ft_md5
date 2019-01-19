/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:27:44 by ori               #+#    #+#             */
/*   Updated: 2019/01/18 19:37:01 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void	usage(void)
{
	ft_printf("{cyan}Usage: ft_ssl command [command opts] [command args]{}");
	ft_error("\n");
}

int			main(int ac, char **av)
{
	if (ac < 2)
		usage();
	
}
