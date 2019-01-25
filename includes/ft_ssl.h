/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:25:48 by ori               #+#    #+#             */
/*   Updated: 2019/01/25 13:23:14 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SSL_H
# define FT_SSL_H

# include	"libft.h"
# define	BUFF_SIZE 1028

typedef enum			e_ehash
{
						md5,
						sha256,
						null
}						t_ehash;

typedef union			u_wb
{
	uint64_t			w;
	uint8_t				b[4];
}						t_wb;

typedef struct			s_ssl_table
{
	const char			*name;
	uint64_t			*(*func)(uint8_t *, uint64_t);
}						t_ssl_table;

uint64_t				*ft_md5(uint8_t *i_msg, uint64_t i_len);
uint64_t				*ft_sha256(uint8_t *i_msg, uint64_t i_len);
void					cmdhandle(char *cmd, char *args);
void					filehandle(char *cmd, char *name);
void					stdinhandle(char *cmd);
void					print_handler(t_ehash hash,
							char *input, uint64_t *output);
void					print_error(char *in);
void					set_glob(void);
void					print_efile(char *name, char *cmd);
extern t_ssl_table		g_lookup[];
extern bool				g_sslflags[];

#endif
