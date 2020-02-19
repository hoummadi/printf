/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:33:41 by hhoummad          #+#    #+#             */
/*   Updated: 2020/01/23 15:02:48 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_variables
{
	int			m_w;
	int			prc;
	char		*pr;
	char		*tmp;
	char		*saver;
	int			min;
	int			max;
	int			save;
	int			len;
	int			type;
	int			size;
	int			num_space;
	char		*str;
}				t_variables;

int				ft_printf(const char *prt, ...);
int				ft_strlen(char *s);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
int				ft_putchar_fd(char c, int fd);
int				ft_atoi2(const char *str);
int				ft_char_printer(char *flag, va_list args);
int				ft_percent_printer(char *flag, va_list arg, const char *prt);
int				ft_atoi(const char *str);
int				ft_string_printer(char *flags, va_list args);
int				ft_strings_precision(int precision, char *string);
int				ft_putstr_fd(char *str, int fd);
char			*ft_strchr(const char *s, int c);
int				ft_p(char *flag, va_list arg);
char			*ft_capital(char *str);
char			*hexa_code(size_t nb, int index);
char			*ft_strrev(char *str);
void			ft_d_assist(char *flag, t_variables *p);
int				ft_digits_printer(char *flag, va_list arg);
int				d_precesion(int precision, t_variables *p);
char			*ft_itoa(long n);
void			ft_u_assist(char *flags, t_variables *p);
int				ft_unsigned_printer(char *flags, va_list args);
int				ft_hexa_printer(char *flags, va_list args, const char *format);
int				helpfree(t_variables *p);
char			*ft_calloc(size_t n, size_t size);

#endif
