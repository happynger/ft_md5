/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:50:36 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/25 10:17:09 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

uint64_t	get_endian(const void *target, size_t bytes)
{
	const uint8_t	*buff;
	uint64_t		result;
	size_t			i;

	i = -1;
	buff = target;
	result = 0;
	while (++i < bytes)
		result = 256 * result + (buff[i] & 0xFF);
	return (result);
}

uint64_t	swap_endian(uint64_t value)
{
	uint64_t	result;

	result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}

uint64_t	rotright(uint64_t value, uint32_t amt)
{
	return ((value >> amt) | (value << (32 - amt)));
}

void		sha_init_w(t_shactx *ctx, uint8_t *msg)
{
	t_sha16		wb;
	int			i;

	i = -1;
	while (++i < 64)
		wb.b[i] = 0;
	ft_memcpy(wb.b, msg, 64);
	i = -1;
	while (++i < 16)
		wb.w[i] = swap_endian(wb.w[i]);
	i = -1;
	while (++i < 16)
		ctx->w[i] = wb.w[i];
}
