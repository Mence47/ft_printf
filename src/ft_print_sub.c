/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:04:45 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/17 15:55:57 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_find_flags(char *sub, t_data *data)
{
	char	str[6];
	int		i;

	str[0] = '-';
	str[1] = '+';
	str[2] = ' ';
	str[3] = '#';
	str[4] = '0';
	i = 0;
	while (i < 4)
		if (ft_strchr(sub, str[i]) != NULL)
			data->flags[i++] = 1;
		else
			data->flags[i++] = 0;
	i = -1;
	while (sub[++i])
		if (sub[i] == '0' && (i == 0 || sub[i - 1] != '.') &&
				(i == 0 || ft_isdigit(sub[i - 1]) == 0))
		{
			data->flags[4] = 1;
			return ;
		}
	data->flags[4] = 0;
}

static int	ft_find_width(char *sub)
{
	int		i;
	int		result;

	i = 0;
	result = -1;
	while (sub[i] != '\0')
	{
		if (ft_isdigit(sub[i]) && sub[i - 1] != '.'
		&& (ft_isdigit(sub[i - 1]) == 0
		|| (sub[i - 1] == '0' && ft_check_point(sub, i))) && sub[i] != '0')
			result = ft_atoi(&sub[i]);
		i++;
	}
	return (result);
}

static int	ft_find_h(char *sub, t_data *data)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (sub[++i])
	{
		if (sub[i] == 'h' && sub[i - 1] != 'h' && sub[i + 1] != 'h')
		{
			data->length[1] = 1;
			return (1);
		}
		if (sub[i] == 'h')
			count++;
	}
	if (count % 2 == 1)
	{
		data->length[1] = 1;
		return (1);
	}
	return (0);
}

static void	ft_find_length(char *sub, t_data *data)
{
	if (ft_strchr(sub, 'L'))
		data->length[4] = 1;
	if (ft_strchr(sub, 'z'))
	{
		data->length[6] = 1;
		return ;
	}
	if (ft_strchr(sub, 'j'))
	{
		data->length[5] = 1;
		return ;
	}
	if (ft_strstr(sub, "ll"))
	{
		data->length[3] = 1;
		return ;
	}
	else if (ft_find_l(sub, data))
		return ;
	if (ft_find_h(sub, data))
		return ;
	if (ft_strstr(sub, "hh"))
		data->length[0] = 1;
}

int			ft_print_sub(va_list ap, char *sub)
{
	t_data	data;

	if (sub == NULL)
		return (0);
	data.length[0] = 0;
	data.length[1] = 0;
	data.length[2] = 0;
	data.length[3] = 0;
	data.length[4] = 0;
	data.length[5] = 0;
	data.length[6] = 0;
	ft_find_flags(sub, &data);
	data.width = ft_find_width(sub);
	if (ft_strrchr(sub, '.') != NULL)
	{
		data.prec = ft_atoi(ft_strrchr(sub, '.') + 1);
		if (ft_check_point_null(ft_strrchr(sub, '.') + 1))
			data.prec = 0;
		if (data.prec < 0)
			data.prec = 0;
	}
	else
		data.prec = -1;
	ft_find_length(sub, &data);
	return (ft_print_data(ap, data, sub[ft_strlen(sub) - 1]));
}
