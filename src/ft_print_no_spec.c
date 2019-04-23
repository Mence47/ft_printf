/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_no_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:21:23 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 20:08:17 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_no_spec(t_data data, char spec)
{
	char	*str;

	if (data.width < 2)
	{
		ft_putchar(spec);
		return (1);
	}
	str = ft_strnew(data.width);
	if (data.flags[0] == 1)
	{
		(void)ft_memset(str, ' ', data.width);
		str[0] = spec;
	}
	else
	{
		if (data.flags[4] == 1)
			(void)ft_memset(str, '0', data.width);
		else
			(void)ft_memset(str, ' ', data.width);
		str[data.width - 1] = spec;
	}
	ft_putstr(str);
	ft_strdel(&str);
	return (data.width);
}
