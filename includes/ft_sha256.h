/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:24:58 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/23 15:19:33 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SHA256_H
# define FT_SHA256_H

#include "libft.h"

typedef union			u_sha16
{
	uint32_t			w[16];
	uint8_t				b[64];
}						t_sha16;

typedef union			u_shawb
{
	uint64_t			w;
	uint8_t				b[8];
}						t_shawb;

typedef struct			s_shactx
{
	uint32_t			h[8];
	uint32_t			w[64];
	uint32_t			abc[8];
	uint32_t			len;
	uint32_t			bits;
}						t_shactx;

uint32_t				changeendian(uint32_t value);
uint32_t				rotright(uint32_t value, uint32_t amt);
void					sha_init_w(t_shactx *ctx, uint8_t *msg);

extern const uint32_t	g_shaconsts[64];

#endif
