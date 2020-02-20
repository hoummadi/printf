/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:17:46 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:07:41 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			star_checker(char **flags, va_list args, int res)
{
	int i;

	i = 0;
	while (flags[0][i] && flags[0][i] != '.')
		if (flags[0][i++] == '*')
			res = (int)va_arg(args, int);
	if (res < 0)
	{
		*flags[0] = '-';
		res *= -1;
	}
	return (res);
}

static int			normal_wid(int wid, char *flags, int *s)
{
	if (*flags != '-' && *flags != '0')
		while (wid > 1)
		{
			*s += ft_putchar_fd(' ', 1);
			wid--;
		}
	else if (*flags == '0')
	{
		while (wid > 1)
		{
			*s += ft_putchar_fd('0', 1);
			wid--;
		}
	}
	return (wid);
}

static int			left_width(int spaces, int s)
{
	while (spaces > 1)
	{
		s += ft_putchar_fd(' ', 1);
		spaces--;
	}
	return (s);
}

int					ft_percent_printer(char *flag, va_list arg, const char *prt)
{
	int s;
	int wid;

	s = 0;
	wid = ft_atoi2(flag);
	wid = star_checker(&flag, arg, wid);
	wid = normal_wid(wid, flag, &s);
	s += ft_putchar_fd(*prt, 1);
	s = left_width(wid, s);
	return (s);
}
