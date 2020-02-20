/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:14:21 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:07:12 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	etoil_chek(char **flag, va_list args, int res)
{
	int i;

	i = 0;
	while (flag[0][i])
		if (flag[0][i++] == '*')
			res = (int)va_arg(args, int);
	if (res < 0)
	{
		*flag[0] = '-';
		res *= -1;
	}
	return (res);
}

int			ft_char_printer(char *flag, va_list args)
{
	int		wid;
	char	pr_arg;
	int		s;

	s = 0;
	wid = ft_atoi2(flag);
	wid = etoil_chek(&flag, args, wid);
	while (wid > 1 && *flag != '-')
	{
		s += ft_putchar_fd(' ', 1);
		wid--;
	}
	pr_arg = (char)va_arg(args, int);
	s += ft_putchar_fd(pr_arg, 1);
	while (wid > 1)
	{
		s += ft_putchar_fd(' ', 1);
		wid--;
	}
	return (s);
}

int			ft_atoi2(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == '-')
		i++;
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}
