/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_format_float.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:46:22 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 21:54:46 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_prec_no_null(char *str, t_data data)
{
	char	*tmp;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	if (data.flags[1] == 1 && ft_isdigit(str[0]))
	{
		*(ft_strncpy(tmp + data.width - ft_strlen(str),
					str, ft_strlen(str)) - 1) = '+';
	}
	else
		ft_strncpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_prec_no_minus(char *str, t_data data)
{
	char		*tmp;

	if (data.flags[4] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		ft_memset(tmp, '0', (size_t)data.width);
		if ((data.flags[1] == 1 || data.flags[2] == 1) && ft_isdigit(str[0]))
		{
			tmp[0] = data.flags[1] == 1 ? '+' : ' ';
			ft_strncpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
		}
		else if (str[0] == '-')
		{
			tmp[0] = '-';
			ft_strncpy(tmp + data.width - ft_strlen(str + 1),
					str + 1, ft_strlen(str + 1));
		}
		else
			ft_strncpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	}
	else
		return (ft_prec_no_null(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_prec(char *str, t_data data)
{
	char		*tmp;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		if (data.flags[1] == 1 && ft_isdigit(str[0]))
		{
			tmp[0] = '+';
			(void)ft_strncpy(tmp + 1, str, ft_strlen(str));
		}
		else if (data.flags[2] == 1 && ft_isdigit(str[0]))
		{
			tmp[0] = ' ';
			(void)ft_strncpy(tmp + 1, str, ft_strlen(str));
		}
		else
			(void)ft_strncpy(tmp, str, ft_strlen(str));
	}
	else
		return (ft_prec_no_minus(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_width_prec(char *str, t_data data)
{
	char		*tmp;

	if (data.flags[1] == 1 && ft_isdigit(str[0]))
	{
		tmp = ft_strjoin("+", str);
		ft_strdel(&str);
		return (tmp);
	}
	else if (data.flags[2] == 1 && ft_isdigit(str[0]))
	{
		tmp = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}

char		*ft_change_format_f(char *str, t_data data)
{
	if (data.width <= (int)ft_strlen(str))
		return (ft_no_width_prec(str, data));
	return (ft_no_prec(str, data));
}
