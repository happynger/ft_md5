/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:24:58 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/25 10:21:29 by otahirov         ###   ########.fr       */
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

typedef struct			s_shactx
{
	uint32_t			h[8];
	uint32_t			w[64];
	uint32_t			abc[8];
	uint64_t			len;
	uint64_t			bits;
}						t_shactx;

uint64_t				get_endian(const void *target, size_t bytes);
uint64_t				rotright(uint64_t value, uint32_t amt);
void					sha_init_w(t_shactx *ctx, uint8_t *msg);

extern const uint32_t	g_shaconsts[64];

#endif
