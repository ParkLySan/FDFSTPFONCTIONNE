/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:06:28 by litoulza          #+#    #+#             */
/*   Updated: 2017/11/27 17:06:34 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char *last_pos;

	last_pos = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_pos = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (last_pos);
}
