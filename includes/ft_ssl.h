/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:25:48 by ori               #+#    #+#             */
/*   Updated: 2019/01/20 14:28:51 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include	"libft.h"

char				*ft_md5(char *i_msg, size_t i_len);
void				cmdhandle(char *cmd, char *args);

typedef struct		s_ssl_table
{
	const char		*name;
	char			*(*func)(char *, size_t);
}					t_ssl_table;

typedef struct		s_hash
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
}					t_hash;

extern u_int32_t	g_origconsts[64];
extern u_int32_t	g_consts[64];
extern t_ssl_table	g_lookup[];
# define TABLE 1

#endif
