/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:54:51 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 20:04:00 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ft_print_decimal(va_list ap, t_data data)
{
	long long	arg;
	char		*str;
	int			size;

	arg = va_arg(ap, long long);
	if (data.length[0] == 1)
		str = ft_itoa((signed char)arg);
	else if (data.length[1] == 1)
		str = ft_itoa((signed short int)arg);
	else if (data.length[2] == 1)
		str = ft_itoa((long int)arg);
	else if (data.length[3] == 1)
		str = ft_itoa(arg);
	else if (data.length[5] == 1)
		str = ft_itoa((intmax_t)arg);
	else if (data.length[6] == 1)
		str = ft_itoa((size_t)arg);
	else
		str = ft_itoa((int)arg);
	str = ft_change_format(str, data);
	ft_putstr(str);
	size = (int)ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
