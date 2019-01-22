/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:18:14 by ori               #+#    #+#             */
/*   Updated: 2019/01/21 17:26:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#define FUNC1(B, C, D) ((B & C) | ((~B) & D))
#define FUNC2(B, C, D) ((D & B) | ((~D) & C))
#define FUNC3(B, C, D) (B ^ C ^ D)
#define FUNC4(B, C, D) (C ^ (B | (~D)))
#define LEFTROT(x, c) ((x << c) | (x >> (32 - c)))

static void		init(t_mdctx *ctx)
{
	ctx->len[0] = 0;
	ctx->len[1] = 0;
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
}

static void		md5_assign(t_mdctx *ctx, int i, uint64_t h[4], uint32_t *m)
{
	ctx->f = ctx->f + h[0] + g_consts[i] + m[ctx->g];
	h[0] = h[3];
	h[3] = h[2];
	h[2] = h[1];
	h[1] = h[1] + LEFTROT(ctx->f, g_origconsts[i]);
}

static void		md5_logic(t_mdctx *ctx, int i, uint64_t h[4], uint32_t *m)
{
	if (i <= 15)
	{
		ctx->f = FUNC1(h[1], h[2], h[3]);
		ctx->g = i;
	}
	else if (i <= 31)
	{
		ctx->f = FUNC2(h[1], h[2], h[3]);
		ctx->g = (5 * i + 1) % 16;
	}
	else if (i <= 47)
	{
		ctx->f = FUNC3(h[1], h[2], h[3]);
		ctx->g = (3 * i + 5) % 16;
	}
	else
	{
		ctx->f = FUNC4(h[1], h[2], h[3]);
		ctx->g = (7 * i) % 16;
	}
	md5_assign(ctx, i, h, m);
}

static void		md5_break(t_mdctx *ctx, uint8_t *msg, size_t n_len)
{
	uint32_t	m[16];
	int			off;
	int			i;
	uint64_t	h[4];

	off = 0;
	while ((size_t)off < n_len)
	{
		i = -1;
		while (++i < 16)
			ft_memcpy(&m[i], msg + (i * 4), 4);
		i = -1;
		while (++i < 4)
			h[i] = ctx->state[i];
		i = -1;
		while (++i < 63)
			md5_logic(ctx, i, h, m);
		i = -1;
		while (++i < 4)
			ctx->state[i] += h[i];
		off += 64;
	}
}

void			ft_md5(uint8_t *i_msg, size_t i_len)
{
	t_mdctx		ctx;
	uint8_t		*msg;
	size_t		n_len;
	uint8_t		digest[16];
	int			i;

	init(&ctx);
	n_len = i_len;
	while (n_len % 64 != 56)
		n_len++;
	msg = ft_memalloc(n_len + 64);
	ft_memcpy(msg, i_msg, i_len);
	msg[i_len] = 0x80;
	md5_put(i_len * 8, msg + n_len);
	md5_put(n_len * 8, msg + n_len + 4);
	md5_break(&ctx, msg, n_len);
	md5_put(ctx.state[0], digest);
	md5_put(ctx.state[1], digest + 4);
	md5_put(ctx.state[2], digest + 8);
	md5_put(ctx.state[3], digest + 12);
	i = -1;
	while (++i < 16)
		ft_printf("%02x", (uint32_t)digest[i]);
	ft_printf("\n");
}
