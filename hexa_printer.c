/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:39:42 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:08:18 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		star_checker(char **flags, va_list args, int res)
{
	int i;
	int width;

	width = res;
	i = 0;
	while (flags[0][i] && flags[0][i] != '.')
	{
		if (flags[0][i++] == '*')
			width = (int)va_arg(args, int);
	}
	if (width < 0)
	{
		*flags[0] = '-';
		width *= -1;
	}
	return (width);
}

static	int		point_checker(char *flags, va_list args, t_variables *p)
{
	int		precesion;

	precesion = -1;
	p->pr = NULL;
	if ((p->pr = ft_strchr(flags, '.')))
	{
		precesion = ft_atoi(++(p->pr));
		if (*(p->pr) == '*')
			precesion = va_arg(args, int);
	}
	return (precesion);
}

int				ft_hexa_printer(char *flag, va_list arg, const char *prt)
{
	unsigned int	handler;
	t_variables		*p;

	p = malloc(sizeof(t_variables));
	p->m_w = ft_atoi2(flag);
	p->m_w = star_checker(&flag, arg, p->m_w);
	p->prc = point_checker(flag, arg, p);
	handler = va_arg(arg, unsigned int);
	p->type = ((*prt == 'x') ? 0 : 1);
	p->str = hexa_code(handler, p->type);
	p->max = ((p->prc > ft_strlen(p->str) ? p->prc : ft_strlen(p->str)));
	if (p->prc == 0 && *(p->str) == '0')
	{
		*(p->str) = ' ';
		p->max -= 1;
	}
	if (p->prc >= 0 && *flag == '0')
		flag += 1;
	p->num_space = p->m_w - p->max;
	ft_u_assist(flag, p);
	free(p->str);
	return (helpfree(p));
}
