/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:25:48 by ori               #+#    #+#             */
/*   Updated: 2019/01/22 16:59:43 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SSL_H
# define FT_SSL_H

# include	"libft.h"

void				ft_md5(uint8_t *i_msg, size_t i_len);
void				cmdhandle(char *cmd, char *args);
void				md5_put(uint32_t data, uint8_t *addr);
uint64_t			f0(uint64_t h[]);
uint64_t			f1(uint64_t h[]);
uint64_t			f2(uint64_t h[]);
uint64_t			f3(uint64_t h[]);

typedef uint64_t	(*md5ff) (uint64_t h[]);

typedef union		u_md5
{
	uint32_t		m[16];
	uint8_t			b[64];
}					t_md5;

typedef union		u_md5h
{
	uint64_t		w;
	uint8_t			b[4];
}					t_md5h;

typedef struct		s_ssl_table
{
	const char		*name;
	void			(*func)(uint8_t *, size_t);
}					t_ssl_table;

typedef struct		s_mdctx
{
	t_md5h			wb;
	uint32_t		j;
	uint64_t		state[4];
}					t_mdctx;

extern const uint32_t	g_consts[64];
extern t_ssl_table		g_lookup[];
extern const uint16_t	*g_rot[];
extern const md5ff		g_ff[];
extern const uint16_t	g_m[];
extern const uint16_t	g_o[];
# define TABLE 1

#endif
