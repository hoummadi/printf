/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 02:31:07 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:09:37 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		normal_precision(int precision, char *string)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (precision > 0 && string[i])
	{
		size += ft_putchar_fd(string[i++], 1);
		precision--;
	}
	return (size);
}

int				ft_strings_precision(int precision, char *string)
{
	int size;

	size = 0;
	size = normal_precision(precision, string);
	if (size == 0 && precision != 0)
		size = ft_putstr_fd(string, 1);
	return (size);
}
