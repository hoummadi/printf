/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:24:59 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/23 10:13:51 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		etoil_chek(char **flags, va_list arg, int res)
{
	int i;
	int wid;

	wid = res;
	i = 0;
	while (flags[0][i] && flags[0][i] != '.')
	{
		if (flags[0][i++] == '*')
			wid = (int)va_arg(arg, int);
	}
	if (wid < 0)
	{
		*flags = ft_strjoin("-", *flags);
		wid *= -1;
	}
	return (wid);
}

static int		point_chek(char *flag, va_list arg, t_variables *p)
{
	int	precesion;

	precesion = -1;
	p->pr = NULL;
	if ((p->pr = ft_strchr(flag, '.')))
	{
		precesion = ft_atoi(++(p->pr));
		if (*(p->pr) == '*')
			precesion = va_arg(arg, int);
	}
	return (precesion);
}

int				ft_digits_printer(char *flag, va_list arg)
{
	int			takearg;
	t_variables	*p;

	p = malloc(sizeof(t_variables));
	p->m_w = ft_atoi2(flag);
	p->m_w = etoil_chek(&flag, arg, p->m_w);
	p->prc = point_chek(flag, arg, p);
	takearg = va_arg(arg, int);
	p->str = ft_itoa(takearg);
	p->tmp = p->str;
	p->max = ((p->prc > ft_strlen(p->str) ? p->prc : ft_strlen(p->str)));
	if (p->prc == 0 && *(p->str) == '0')
	{
		*(p->str) = ' ';
		p->max -= 1;
	}
	if (p->prc >= 0 && *flag == '0')
		flag += 1;
	if (*(p->str) == '-' && p->prc >= ft_strlen(p->str))
		p->max += 1;
	p->num_space = p->m_w - p->max;
	ft_d_assist(flag, p);
	free(p->tmp);
	return (helpfree(p));
}
