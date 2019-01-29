/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:24:48 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/28 17:40:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

#define F1(w) (rotright(w,  7) ^ rotright(w, 18) ^ (w >>  3))
#define F2(w) (rotright(w, 17) ^ rotright(w, 19) ^ (w >> 10))

#define L1(x) (rotright(x, 6) ^ rotright(x, 11) ^ rotright(x, 25))
#define L2(e, f, g) ((e & f) ^ (~e & g))
#define L3(x) (rotright(x, 2) ^ rotright(x, 13) ^ rotright(x, 22))
#define L4(a, b, c) ((a & b) ^ (a & c) ^ (b & c))

static void	sha_init(t_shactx *ctx, uint32_t len)
{
	ctx->h[0] = 0x6a09e667;
	ctx->h[1] = 0xbb67ae85;
	ctx->h[2] = 0x3c6ef372;
	ctx->h[3] = 0xa54ff53a;
	ctx->h[4] = 0x510e527f;
	ctx->h[5] = 0x9b05688c;
	ctx->h[6] = 0x1f83d9ab;
	ctx->h[7] = 0x5be0cd19;
	ctx->len = len >> 3;
	ctx->bits = len;
}

/*
**	abc[0] ->> a
**	abc[1] ->> b
**	abc[2] ->> c
**	abc[3] ->> d
**	abc[4] ->> e
**	abc[5] ->> f
**	abc[6] ->> g
**	abc[7] ->> h
*/

static void	ft_shalogic(t_shactx *ctx)
{
	int			i;
	uint64_t	s[2];
	uint64_t	ch;
	uint64_t	tmp[2];
	uint64_t	maj;

	i = -1;
	while (++i < 64)
	{
		s[1] = L1(ctx->abc[4]);
		ch = L2(ctx->abc[4], ctx->abc[5], ctx->abc[6]);
		tmp[0] = ctx->abc[7] + s[1] + ch + g_shaconsts[i] + ctx->w[i];
		s[0] = L3(ctx->abc[0]);
		maj = L4(ctx->abc[0], ctx->abc[1], ctx->abc[2]);
		tmp[1] = s[0] + maj;
		ctx->abc[7] = ctx->abc[6];
		ctx->abc[6] = ctx->abc[5];
		ctx->abc[5] = ctx->abc[4];
		ctx->abc[4] = ctx->abc[3] + tmp[0];
		ctx->abc[3] = ctx->abc[2];
		ctx->abc[2] = ctx->abc[1];
		ctx->abc[1] = ctx->abc[0];
		ctx->abc[0] = tmp[0] + tmp[1];
	}
}

static void	ft_shadigest(t_shactx *ctx, uint8_t *msg)
{
	uint32_t	off;
	int			i;
	uint64_t	tmp[2];

	off = -64;
	while ((off += 64) < ctx->len)
	{
		sha_init_w(ctx, msg + off);
		i = 15;
		while (++i < 64)
		{
			tmp[0] = F1(ctx->w[i - 15]);
			tmp[1] = F2(ctx->w[i - 2]);
			ctx->w[i] = ctx->w[i - 16] + tmp[0] + ctx->w[i - 7] + tmp[1];
		}
		i = -1;
		while (++i < 8)
			ctx->abc[i] = ctx->h[i];
		ft_shalogic(ctx);
		i = -1;
		while (++i < 8)
			ctx->h[i] += ctx->abc[i];
	}
}

uint64_t	*ft_sha256(uint8_t *i_msg, uint64_t i_len)
{
	uint64_t	len;
	uint8_t		*msg;
	t_shactx	ctx;
	uint64_t	bits;
	uint64_t	*result;

	len = 0;
	while ((len + 1 + (i_len << 3) + 64) % 512 != 0)
		len++;
	msg = ft_memalloc((len >> 3) + i_len + 8 + 1);
	ft_memcpy(msg, i_msg, i_len);
	msg[i_len] = 0x80;
	sha_init(&ctx, len + 1 + (i_len << 3) + 64);
	bits = i_len << 3;
	bits = get_endian(&bits, 8);
	ft_memcpy(msg + (len >> 3) + i_len + 1, &bits, 8);
	ft_shadigest(&ctx, msg);
	ft_memdel((void **)&msg);
	len = -1;
	result = ft_memalloc(8 * sizeof(uint64_t));
	while (++len < 8)
		result[len] = ctx.h[len];
	return (result);
}
