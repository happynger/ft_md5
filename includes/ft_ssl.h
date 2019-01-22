/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:25:48 by ori               #+#    #+#             */
/*   Updated: 2019/01/21 16:57:14 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include	"libft.h"

void				ft_md5(uint8_t *i_msg, size_t i_len);
void				cmdhandle(char *cmd, char *args);
void				md5_put(uint32_t data, uint8_t *addr);

typedef struct		s_ssl_table
{
	const char		*name;
	void			(*func)(uint8_t *, size_t);
}					t_ssl_table;

typedef struct		s_mdctx
{
	uint64_t		state[4];
	uint64_t		len[2];
	uint32_t		f;
	uint32_t		g;
}					t_mdctx;

extern uint32_t	g_origconsts[64];
extern uint32_t	g_consts[64];
extern t_ssl_table	g_lookup[];
# define TABLE 1

#endif
