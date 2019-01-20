/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:18:14 by ori               #+#    #+#             */
/*   Updated: 2019/01/20 14:25:23 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#define FUNC1(B, C, D) ((B & C) | ((~B) & D))
#define FUNC2(B, C, D) ((D & B) | ((~D) & C))
#define FUNC3(B, C, D) (B ^ C ^ D)
#define FUNC4(B, C, D) (C ^ (B | (~D)))
#define LEFTROT(x, c) ((x << c) | (x >> (32 - c)))

static int		setup(size_t i_len, t_hash *ret)
{
	int		len;

	ret->a = 0x67452301;
	ret->b = 0xefcdab89;
	ret->c = 0x98badcfe;
	ret->d = 0x10325476;
	len = i_len * 8 + 1;
	while (len % 512 != 488)
		len++;
	len /= 8;
	return (len);
}

static void		assign(int f, t_hash *tmp_h, int i, int g, u_int32_t *tmp)
{
	f = f + tmp_h->a + g_consts[i] + tmp[g];
	tmp_h->a = tmp_h->d;
	tmp_h->d = tmp_h->c;
	tmp_h->c = tmp_h->b;
	tmp_h->b = tmp_h->b + LEFTROT(f, g_origconsts[i]);
}

static void		logic(t_hash *tmp_h, int i, u_int32_t *tmp)
{
	int		f;
	int		g;

	if (i < 15)
	{
		f = FUNC1(tmp_h->b, tmp_h->c, tmp_h->d);
		g = i;
	}
	else if (i >= 16 && i <= 31)
	{
		f = FUNC2(tmp_h->b, tmp_h->c, tmp_h->d);
		g = (5 * i + 1) % 16;
	}
	else if (i >= 32 && i <= 47)
	{
		f = FUNC3(tmp_h->b, tmp_h->c, tmp_h->d);
		g = (3 * i + 5) % 16;
	}
	else
	{
		f = FUNC4(tmp_h->b, tmp_h->c, tmp_h->d);
		g = (7 * i) % 16;
	}
	assign(f, tmp_h, i, g, tmp);
}

static void		breaker(char *msg, t_hash *ret, int len)
{
	int			off;
	u_int32_t	*tmp;
	t_hash		tmp_h;
	int			i;

	off = 0;
	while (off < len)
	{
		i = 0;
		tmp = (u_int32_t *)(msg + off);
		off += 64;
		tmp_h.a = ret->a;
		tmp_h.b = ret->b;
		tmp_h.c = ret->c;
		tmp_h.d = ret->d;
		while (i < 64)
			logic(&tmp_h, i++, tmp);
		ret->a += tmp_h.a;
		ret->b += tmp_h.b;
		ret->c += tmp_h.c;
		ret->d += tmp_h.d;
	}
}

char			*ft_md5(char *i_msg, size_t i_len)
{
	char		*msg;
	int			len;
	t_hash		ret;
	u_int32_t	bits;
	char		*tmp[2];

	len = setup(i_len, &ret);
	msg = (char *)ft_memalloc((len + 64) * sizeof(char));
	ft_memcpy(msg, i_msg, i_len);
	msg[i_len] = 0x80;
	bits = i_len * 8;
	ft_memcpy(msg + len, &bits, 4);
	breaker(msg, &ret, len);
	tmp[0] = ft_strjoin((char *)&ret.a, (char *)&ret.b);
	tmp[1] = ft_strjoin(tmp[0], (char *)&ret.c);
	ft_strdel(&tmp[0]);
	tmp[0] = ft_strjoin(tmp[1], (char *)&ret.d);
	ft_strdel(&tmp[1]);
	ft_strdel(&msg);
	return (tmp[0]);
}