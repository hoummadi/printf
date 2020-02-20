/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:59:06 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/21 21:00:28 by hhoummad         ###   ########.fr       */
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

int				d_precesion(int precision, t_variables *p)
{
	int size;

	size = 0;
	if (*(p->str) == '-')
	{
		size += ft_putchar_fd('-', 1);
		p->str += 1;
	}
	size += normal_precision(precision, p->str);
	return (size);
}
