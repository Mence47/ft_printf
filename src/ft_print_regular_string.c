/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_regular_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:17:23 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:40:45 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_print_regular_string(t_data *data, char *arg)
{
	char	*str;

	if (arg == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(arg);
	if (data->prec != -1)
	{
		if (data->prec == 0)
		{
			arg = ft_strdup("");
			ft_strdel(&str);
			str = arg;
		}
		else if (data->prec < (int)ft_strlen(str))
		{
			arg = ft_strnew(data->prec);
			ft_memcpy(arg, str, data->prec);
			ft_strdel(&str);
			str = arg;
		}
		data->prec = -1;
	}
	return (str);
}
