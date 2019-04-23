/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:00:34 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/17 15:56:18 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_set_length(t_data *data)
{
	data->length[0] = 0;
	data->length[1] = 0;
	data->length[2] = 1;
	data->length[3] = 0;
	data->length[4] = 0;
	data->length[5] = 0;
	data->length[6] = 0;
}

static int	ft_find_spec(char *str, char spec, t_data *data)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		if (spec == str[i])
		{
			if (str[i] < 'a' && str[i] != 'X')
				ft_set_length(data);
			return (i);
		}
		i++;
	}
	return (-1);
}

int			ft_print_data(va_list ap, t_data data, char spec)
{
	int		i;
	char	str[17];
	int		(*f[17])(va_list, t_data);

	ft_strcpy(str, "cCsSpdDioOuUxXf%");
	f[0] = ft_print_char;
	f[1] = ft_print_char;
	f[2] = ft_print_string;
	f[3] = ft_print_string;
	f[4] = ft_print_pointer;
	f[5] = ft_print_decimal;
	f[6] = ft_print_decimal;
	f[7] = ft_print_decimal;
	f[8] = ft_print_octal;
	f[9] = ft_print_octal;
	f[10] = ft_print_unsigned;
	f[11] = ft_print_unsigned;
	f[12] = ft_print_hex;
	f[13] = ft_print_hex_capital;
	f[14] = ft_print_float;
	f[15] = ft_print_percent;
	i = ft_find_spec(str, spec, &data);
	if (i == -1)
		return (ft_print_no_spec(data, spec));
	return (f[i](ap, data));
}
