/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:18:14 by ori               #+#    #+#             */
/*   Updated: 2019/01/25 12:27:00 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_md5.h"

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
		g[1] = h[1] + leftrotate(h[0] + fct(h) + g_md5consts[j + 16 * i] +
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

uint64_t		*ft_md5(uint8_t *i_msg, uint64_t i_len)
{
	t_mdctx		ctx;
	uint8_t		*msg;
	size_t		n_len;
	uint64_t	*result;
	int			i;

	init(&ctx);
	n_len = i_len;
	while ((n_len * 8) % 512 != 448)
		n_len++;
	msg = ft_memalloc(n_len + 64);
	ft_memcpy(msg, i_msg, i_len);
	msg[i_len] = 0x80;
	i = 64 * ((n_len / 64) + 1) - 8;
	ctx.j = 8 * i_len;
	ft_memcpy(msg + i, &ctx.j, 4);
	md5_break(&ctx, msg, n_len);
	ft_memdel((void **)&msg);
	result = ft_memalloc(4 * sizeof(uint64_t));
	i = -1;
	while (++i < 4)
		result[i] = ctx.state[i];
	return (result);
}
