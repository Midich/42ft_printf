/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:05:34 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/30 13:17:53 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

typedef struct s_format
{
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	conversion;
}	t_format;

int			ft_printf(const char *s, ...);
t_format	*ft_parse_specifiers(const char *frmt, int *i);
int		ft_handle_specifiers(t_format spec, va_list ap);
int		ft_print_character(t_format spec, char c);
int		ft_print_string(t_format spec, char *s);
int		ft_print_pointer(t_format spec, uintptr_t p);
int		ft_print_integer(t_format spec, int i);
int		ft_print_uinteger(t_format spec, unsigned int i);
int		ft_print_hex(t_format spec, unsigned int u);
int		ft_print_hex(t_format spec, unsigned int u);

#endif
