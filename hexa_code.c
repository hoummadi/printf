/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:23:58 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/25 01:08:05 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexa_code(size_t nb, int index)
{
	int		r;
	char	*buffer;
	char	*hexa_base;
	int		i;

	r = 0;
	i = 0;
	buffer = malloc(30);
	hexa_base = ft_strdup("0123456789abcdef");
	while (nb >= 16)
	{
		r = nb % 16;
		buffer[i++] = hexa_base[r];
		nb /= 16;
	}
	r = nb;
	buffer[i++] = hexa_base[r];
	buffer[i] = '\0';
	buffer = ft_strrev(buffer);
	if (index == 1)
		buffer = ft_capital(buffer);
	free(hexa_base);
	return (buffer);
}

char	*ft_capital(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*ft_strrev(char *str)
{
	int compteur;
	int size;
	int swap;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	compteur = 0;
	while (size > compteur)
	{
		swap = str[size - 1];
		str[size - 1] = str[compteur];
		str[compteur] = swap;
		size--;
		compteur++;
	}
	return (str);
}
