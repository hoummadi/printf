/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 02:29:56 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:09:24 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		etoil_check(char **flags, va_list args, int res)
{
	int		i;
	int		result;

	i = 0;
	result = res;
	while (flags[0][i] != '.' && flags[0][i])
		if (flags[0][i++] == '*')
			result = va_arg(args, int);
	if (result < 0)
	{
		flags[0][0] = '-';
		result *= -1;
	}
	return (result);
}

static	int		point_check(char *flags, va_list args)
{
	char	*point_position;
	int		precesion;

	precesion = -1;
	point_position = NULL;
	if ((point_position = ft_strchr(flags, '.')))
	{
		precesion = ft_atoi(++point_position);
		if (*point_position == '*')
			precesion = va_arg(args, int);
	}
	return (precesion);
}

static int		normal_wid(int wid, char *flags, t_variables *p)
{
	int i;

	i = 0;
	p->size = 0;
	while (wid > 0 && *flags != '-')
	{
		p->size += ft_putchar_fd(' ', 1);
		wid--;
	}
	return (wid);
}

int				ft_string_printer(char *flags, va_list args)
{
	t_variables		*p;

	p = malloc(sizeof(t_variables));
	p->m_w = ft_atoi2(flags);
	p->m_w = etoil_check(&flags, args, p->m_w);
	p->prc = point_check(flags, args);
	p->str = va_arg(args, char *);
	if (p->str == NULL)
		p->str = "(null)";
	p->min = ((p->prc < ft_strlen(p->str) && (p->prc >= 0)) ?
			p->prc : ft_strlen(p->str));
	if (p->min < 0)
		p->min *= -1;
	p->num_space = p->m_w - p->min;
	p->num_space = normal_wid(p->num_space, flags, p);
	p->size += ft_strings_precision(p->prc, p->str);
	while (p->num_space > 0)
	{
		p->size += ft_putchar_fd(' ', 1);
		p->num_space--;
	}
	return (helpfree(p));
}
