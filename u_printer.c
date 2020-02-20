/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:38:01 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:07:30 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		etoil_check(char **flag, va_list arg, int r)
{
	int i;
	int wid;

	wid = r;
	i = 0;
	while (flag[0][i] && flag[0][i] != '.')
	{
		if (flag[0][i++] == '*')
			wid = (int)va_arg(arg, int);
	}
	if (wid < 0)
	{
		*flag[0] = '-';
		wid *= -1;
	}
	return (wid);
}

static int		point_check(char *flags, va_list args, t_variables *p)
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

int				ft_unsigned_printer(char *flag, va_list args)
{
	unsigned int	takearg;
	t_variables		*p;

	p = malloc(sizeof(t_variables));
	p->m_w = ft_atoi2(flag);
	p->m_w = etoil_check(&flag, args, p->m_w);
	p->prc = point_check(flag, args, p);
	takearg = va_arg(args, unsigned int);
	p->str = ft_itoa(takearg);
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
