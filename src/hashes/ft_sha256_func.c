/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:50:36 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/23 15:21:28 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

uint32_t	changeendian(uint32_t value)
{
	uint32_t	res;

	res = 0;
	res |= (value & 0x000000FF) << 24;
	res |= (value & 0x0000FF00) << 8;
	res |= (value & 0x00FF0000) >> 8;
	res |= (value & 0xFF000000) >> 24;
	return (res);
}

uint32_t	rotright(uint32_t value, uint32_t amt)
{
	return ((value >> amt) | (value << (32 - amt)));
}

void		sha_init_w(t_shactx *ctx, uint8_t *msg)
{
	t_sha16		wb;
	int			i;

	ft_memcpy(wb.b, msg, 64);
	i = -1;
	while (++i < 16)
		ctx->w[i] = wb.w[i];
}
