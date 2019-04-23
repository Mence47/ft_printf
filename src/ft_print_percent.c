/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:00:31 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:37:16 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_percent(va_list ap, t_data data)
{
	char	*str;

	ap = NULL;
	if (data.width < 2)
	{
		ft_putchar('%');
		return (1);
	}
	str = ft_strnew(data.width);
	if (data.flags[0] == 1)
	{
		(void)ft_memset(str, ' ', data.width);
		str[0] = '%';
	}
	else
	{
		if (data.flags[4] == 1)
			(void)ft_memset(str, '0', data.width);
		else
			(void)ft_memset(str, ' ', data.width);
		str[data.width - 1] = '%';
	}
	ft_putstr(str);
	ft_strdel(&str);
	return (data.width);
}
