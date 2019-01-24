/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:54:44 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/23 12:19:48 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_md5.h"

void		md5_put(uint32_t data, uint8_t *addr)
{
	addr[0] = (uint8_t)data;
	addr[1] = (uint8_t)(data >> 8);
	addr[2] = (uint8_t)(data >> 16);
	addr[3] = (uint8_t)(data >> 24);
}

uint64_t	f0(uint64_t h[])
{
	return ((h[1] & h[2]) | (~h[1] & h[3]));
}

uint64_t	f1(uint64_t h[])
{
	return ((h[3] & h[1]) | (~h[3] & h[2]));
}

uint64_t	f2(uint64_t h[])
{
	return (h[1] ^ h[2] ^ h[3]);
}

uint64_t	f3(uint64_t h[])
{
	return (h[2] ^ (h[1] | ~h[3]));
}
