/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:08:32 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:09:11 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (*(p->str) == '-')
		{
			p->size += ft_putchar_fd(*(p->str), 1);
			p->str += 1;
		}
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

void			ft_d_assist(char *flag, t_variables *p)
{
	p->num_space = normal_wid(p->num_space, flag, p);
	p->size += d_precesion(p->prc, p);
	if (*(p->str) != ' ')
		p->size += ft_putstr_fd(p->str, 1);
	left_wid(p->num_space, p);
}
