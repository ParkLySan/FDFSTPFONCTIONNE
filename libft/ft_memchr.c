/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:41:57 by litoulza          #+#    #+#             */
/*   Updated: 2017/12/06 16:54:55 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *strsrc;

	strsrc = (unsigned char*)src;
	while (len > 0 && *strsrc != (unsigned char)c)
	{
		len--;
		strsrc++;
	}
	if (len == 0)
		return (NULL);
	else
		return (strsrc);
}
