/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:33:07 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:08:43 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_check(const char **prt)
{
	int		i;
	char	*flag;
	char	*save;
	char	*tmp;

	i = 0;
	flag = malloc(1);
	*flag = '\0';
	save = ft_calloc(2, 1);
	while (*prt[0] != 'c' && *prt[0] != 's' && *prt[0] != 'p' &&
			*prt[0] != 'd' && *prt[0] != 'i' && *prt[0] != 'u' &&
			*prt[0] != 'x' && *prt[0] != 'X' && *prt[0] != '%')
	{
		save[0] = *prt[0];
		tmp = flag;
		flag = ft_strjoin(flag, save);
		free(tmp);
		*prt += 1;
	}
	free(save);
	return (flag);
}

int		print_prt(char *flags, va_list args, const char *prt)
{
	int	size;

	size = 0;
	if (*prt == '%')
		size += ft_percent_printer(flags, args, prt);
	if (*prt == 'c')
		size += ft_char_printer(flags, args);
	if (*prt == 's')
		size += ft_string_printer(flags, args);
	if (*prt == 'p')
		size += ft_p(flags, args);
	if (*prt == 'd' || *prt == 'i')
		size += ft_digits_printer(flags, args);
	if (*prt == 'u')
		size += ft_unsigned_printer(flags, args);
	if (*prt == 'x' || *prt == 'X')
		size += ft_hexa_printer(flags, args, prt);
	return (size);
}

int		ft_printf(const char *prt, ...)
{
	va_list	args;
	char	*flags_saver;
	int		s;
	char	*tmp;

	s = 0;
	va_start(args, prt);
	while (*prt)
	{
		if (*prt == '%')
		{
			prt++;
			flags_saver = type_check(&prt);
			tmp = flags_saver;
			s += print_prt(flags_saver, args, prt);
			free(tmp);
		}
		else
			s += ft_putchar_fd(*prt, 1);
		prt++;
	}
	va_end(args);
	return (s);
}
