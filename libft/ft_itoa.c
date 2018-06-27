/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:54:37 by litoulza          #+#    #+#             */
/*   Updated: 2017/12/12 17:56:21 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchars(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0 && (n = n * -1))
		i++;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	x;
	int				sign;
	char			*buf;

	if (!(buf = ft_strnew(ft_countchars(n))))
		return (0);
	x = n;
	if ((sign = n) < 0)
		x = -n;
	i = 0;
	if (x == 0)
		buf[i++] = '0';
	while (x > 0)
	{
		buf[i++] = x % 10 + '0';
		x /= 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}
