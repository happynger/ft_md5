/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:54:44 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/21 16:57:02 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_put(uint32_t data, uint8_t *addr)
{
	addr[0] = (uint8_t)data;
	addr[1] = (uint8_t)(data >> 8);
	addr[2] = (uint8_t)(data >> 16);
	addr[3] = (uint8_t)(data >> 24);
}
