/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_assist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:13:02 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:07:21 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		normal_precision(int precision, char *string)
{
	int size;

	size = 0;
	while (precision > ft_strlen(string))
	{
		size += ft_putchar_fd('0', 1);
		precision--;
	}
	return (size);
}

static int		udigits_precision(int precision, t_variables *p)
{
	int size;

	size = 0;
	size += normal_precision(precision, p->str);
	return (size);
}

static int		normal_wid(int width, char *flags, t_variables *p)
{
	p->size = 0;
	if (*flags != '-' && *flags != '0')
		while (width > 0)
		{
			p->size += ft_putchar_fd(' ', 1);
			width--;
		}
	else if (*flags == '0')
	{
		while (width > 0)
		{
			p->size += ft_putchar_fd('0', 1);
			width--;
		}
	}
	return (width);
}

static void		left_wid(int spaces, t_variables *p)
{
	while (spaces > 0)
	{
		p->size += ft_putchar_fd(' ', 1);
		spaces--;
	}
}

void			ft_u_assist(char *flags, t_variables *p)
{
	p->num_space = normal_wid(p->num_space, flags, p);
	p->size += udigits_precision(p->prc, p);
	if (*(p->str) != ' ')
		p->size += ft_putstr_fd(p->str, 1);
	left_wid(p->num_space, p);
}
