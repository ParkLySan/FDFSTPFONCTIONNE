/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:49:41 by litoulza          #+#    #+#             */
/*   Updated: 2017/11/27 16:49:48 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	char *s1iter;

	s1iter = s1;
	while (*s1iter != '\0')
		s1iter++;
	while (len-- > 0 && *s2 != '\0')
		*s1iter++ = *s2++;
	*s1iter = '\0';
	return (s1);
}
