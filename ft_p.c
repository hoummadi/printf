/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:59:04 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:08:37 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		norm_wid(int pa, char *flag, t_variables *p)
{
	p->size = 0;
	while (pa > 0 && *flag != '-')
	{
		p->size += ft_putchar_fd(' ', 1);
		pa--;
	}
	return (pa);
}

static void		left_wid(int pa, t_variables *p)
{
	while (pa > 0)
	{
		p->size += ft_putchar_fd(' ', 1);
		pa--;
	}
}

static int		etoil_check(char **flag, va_list arg, int r)
{
	int i;
	int wid;

	wid = r;
	i = 0;
	while (flag[0][i])
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

int				ft_p(char *flag, va_list arg)
{
	unsigned long			chek;
	t_variables				*p;

	p = malloc(sizeof(t_variables));
	p->saver = ft_strdup("0x");
	p->m_w = ft_atoi2(flag);
	p->m_w = etoil_check(&flag, arg, p->m_w);
	chek = va_arg(arg, size_t);
	p->str = hexa_code(chek, 0);
	p->tmp = p->str;
	if (!(ft_strchr(flag, '.') != NULL && chek == 0))
	{
		p->str = ft_strjoin(p->saver, p->str);
	}
	else
		p->str = ft_strdup(p->saver);
	p->num_space = p->m_w - ft_strlen(p->str);
	p->num_space = norm_wid(p->num_space, flag, p);
	p->size += ft_putstr_fd(p->str, 1);
	left_wid(p->num_space, p);
	free(p->str);
	free(p->tmp);
	free(p->saver);
	return (helpfree(p));
}
