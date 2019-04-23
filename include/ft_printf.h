/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:41:21 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/17 15:53:59 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <libft.h>

typedef struct	s_data
{
	int			flags[5];
	int			prec;
	int			width;
	int			length[7];

}				t_data;

int				ft_printf(const char *format, ...);
int				ft_print_sub(va_list ap, char *sub);
int				ft_print_data(va_list ap, t_data data, char spec);
int				ft_print_char(va_list ap, t_data data);
int				ft_print_string(va_list ap, t_data data);
int				ft_print_pointer(va_list ap, t_data data);
int				ft_print_decimal(va_list ap, t_data data);
int				ft_print_octal(va_list ap, t_data data);
int				ft_print_unsigned(va_list ap, t_data data);
int				ft_print_hex(va_list ap, t_data data);
int				ft_print_hex_capital(va_list ap, t_data data);
int				ft_print_float(va_list ap, t_data data);
int				ft_print_percent(va_list ap, t_data data);
int				ft_print_no_spec(t_data data, char spec);
char			*ft_change_format(char *str, t_data data);
char			*ft_change_format_h(char *str, t_data data);
char			*ft_change_format_h_capital(char *str, t_data data);
char			*ft_change_format_p(char *str, t_data data);
char			*ft_change_format_o(char *str, t_data data);
char			*ft_prec(char *str, t_data data);
int				ft_check_point(char *sub, int i);
int				ft_check_point_null(char *sub);
char			*ft_prec_u(char *str, t_data data);
char			*ft_prec_o(char *str, t_data data);
char			*ft_prec_h(char *str, t_data data);
int				ft_check_null(char *sub);
char			*ft_prec_h_capital(char *str, t_data data);
char			*ft_prec_p(char *str, t_data data);
char			*ft_print_unicode_char(va_list ap, int *flag);
char			*ft_print_unicode_str(va_list ap, t_data data);
char			*ft_print_regular_string(t_data *data, char *arg);
int				ft_find_l(char *sub, t_data *data);
char			*ft_change_format_u(char *str, t_data data);
char			*ft_change_format_f(char *str, t_data data);
int				ft_round(char **str);

#endif
