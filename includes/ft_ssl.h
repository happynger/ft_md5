/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:25:48 by ori               #+#    #+#             */
/*   Updated: 2019/01/23 13:48:12 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SSL_H
# define FT_SSL_H

# include	"libft.h"

void				ft_md5(uint8_t *i_msg, size_t i_len);
void				ft_sha256(uint8_t *i_msg, size_t i_len);
void				cmdhandle(char *cmd, char *args);

typedef struct		s_ssl_table
{
	const char		*name;
	void			(*func)(uint8_t *, size_t);
}					t_ssl_table;

extern t_ssl_table		g_lookup[];

#endif
