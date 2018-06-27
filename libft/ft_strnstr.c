/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:17:17 by litoulza          #+#    #+#             */
/*   Updated: 2017/12/06 19:53:07 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t hlen)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)(haystack));
	while (i <= hlen && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && j < ft_strlen(needle))
			{
				if ((i + j) >= hlen)
					return (NULL);
				if (j == ft_strlen(needle) - 1)
					return ((char *)haystack + i);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
