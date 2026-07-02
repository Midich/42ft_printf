/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:05:34 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 14:29:32 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct s_spec
{
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	conversion;
}	t_spec;

int		ft_printf(const char *s, ...);
t_spec	*ft_parse_specifiers(const char *frmt, int *i);
int		ft_handle_specifiers(t_spec *spec, va_list ap);
int		ft_print_character(t_spec *spec, int c);
int		ft_print_string(t_spec *spec, char *s);
int		ft_print_integer(t_spec *spec, int i);
int		ft_print_uinteger(t_spec *spec, unsigned int i);
int		ft_print_hex(t_spec *spec, unsigned int u);
int		ft_print_pointer(t_spec *spec, unsigned long int u);

char	*ft_format_precision(t_spec *spec, char *si);
char	*ft_format_sign_space(t_spec *spec, char *si);
char	*ft_format_width(t_spec *spec, char *si);

char	*ft_utoa(unsigned int a);
char	*ft_hextoa(unsigned long int a);

#endif
