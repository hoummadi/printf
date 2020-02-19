/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:58:31 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/21 21:03:57 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	lena(long n)
{
	if (n <= 9)
		return (1);
	return (lena(n / 10) + 1);
}

static	void	remp(char *s, long j, int i)
{
	if (j <= 9)
		s[--i] = j + '0';
	else
	{
		s[--i] = (j % 10) + '0';
		remp(s, j / 10, i);
	}
}

char			*ft_itoa(long j)
{
	int		i;
	char	*s;
	long	n;

	i = 0;
	if (j < 0)
	{
		i = 1;
		j = -j;
	}
	n = lena(j);
	if (!n)
		return (NULL);
	if (!(s = malloc(1 + i + n)))
		return (0);
	remp(s, j, n + i);
	s[n + i] = '\0';
	if (i == 1)
		s[0] = '-';
	return (s);
}
