/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:18:14 by ori               #+#    #+#             */
/*   Updated: 2019/01/22 16:52:44 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		init(t_mdctx *ctx)
{
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
}

static uint32_t	leftrotate(uint32_t v, uint16_t amt)
{
	uint32_t	msk;

	msk = (1 << amt) - 1;
	return (((v >> (32 - amt)) & msk) | ((v << amt) & ~msk));
}

static void		md5_logic(int i, uint64_t h[4], uint32_t *mb)
{
	md5ff			fct;
	const uint16_t	*rot;
	uint16_t		m[2];
	uint64_t		g[2];
	int				j;

	fct = g_ff[i];
	rot = g_rot[i];
	m[0] = g_m[i];
	m[1] = g_o[i];
	j = -1;
	while (++j < 16)
	{
		g[0] = (m[0] * j + m[1]) % 16;
		g[1] = h[1] + leftrotate(h[0] + fct(h) + g_consts[j + 16 * i] +
			mb[g[0]], rot[j % 4]);
		h[0] = h[3];
		h[3] = h[2];
		h[2] = h[1];
		h[1] = g[1];
	}
}

static void		md5_break(t_mdctx *ctx, uint8_t *msg, size_t n_len)
{
	t_md5		m;
	int			off;
	int			i;
	uint64_t	h[4];

	off = 0;
	while ((size_t)off < n_len)
	{
		ft_memcpy(m.b, msg + off, 64);
		i = -1;
		while (++i < 4)
			h[i] = ctx->state[i];
		i = -1;
		while (++i < 4)
			md5_logic(i, h, m.m);
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
	int			i[2];

	init(&ctx);
	n_len = 1 + (i_len * 8) / 64;
	msg = ft_memalloc(n_len * 64);
	ft_memcpy(msg, i_msg, i_len);
	msg[i_len] = 0x80;
	i[0] = i_len + 1;
	while ((size_t)i[0] < n_len * 64)
	{
		ctx.j = 8 * i_len;
		i[0] -= 8;
		ft_memcpy(msg + i[0], &ctx.j, 4);
	}
	md5_break(&ctx, msg, n_len);
	i[0] = -1;
	while (++i[0] < 4)
	{
		ctx.wb.w = ctx.state[i[0]];
		i[1] = -1;
		while (++i[1] < 4)
			ft_printf("%02x", ctx.wb.b[i[1]]);
	}
	ft_printf("\n");
}
