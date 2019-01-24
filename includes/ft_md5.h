/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:17:27 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/23 12:35:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

#include "libft.h"

void					md5_put(uint32_t data, uint8_t *addr);
uint64_t				f0(uint64_t h[]);
uint64_t				f1(uint64_t h[]);
uint64_t				f2(uint64_t h[]);
uint64_t				f3(uint64_t h[]);

typedef uint64_t		(*md5ff) (uint64_t h[]);

typedef union			u_md5
{
	uint32_t			m[16];
	uint8_t				b[64];
}						t_md5;

typedef union			u_md5h
{
	uint64_t			w;
	uint8_t				b[4];
}						t_md5h;


typedef struct			s_mdctx
{
	t_md5h				wb;
	uint32_t			j;
	uint64_t			state[4];
}						t_mdctx;

extern const uint32_t	g_md5consts[64];
extern const uint16_t	*g_rot[];
extern const md5ff		g_ff[];
extern const uint16_t	g_m[];
extern const uint16_t	g_o[];

#endif
