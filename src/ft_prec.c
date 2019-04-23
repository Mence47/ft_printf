/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:26:10 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:38:34 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_no_width_prec(char *str, t_data data, int sign)
{
	char			*tmp;

	if (data.flags[1] == 1 && sign == 1)
	{
		tmp = ft_strjoin("+", str);
		ft_strdel(&str);
		return (tmp);
	}
	else if (data.flags[2] == 1 && sign == 1)
	{
		tmp = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (tmp);
	}
	else if (sign == -1)
	{
		tmp = ft_strjoin("-", str);
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}

static char	*ft_prec_no_null(char *str, t_data data, int sign)
{
	char	*tmp;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	if (data.flags[1] == 1 && sign == 1)
	{
		*(ft_strncpy(tmp + data.width - ft_strlen(str),
					str, ft_strlen(str)) - 1) = '+';
	}
	else if (sign == -1)
		*(ft_strncpy(tmp + data.width - ft_strlen(str),
					str, ft_strlen(str)) - 1) = '-';
	else
		ft_strncpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_prec(char *str, t_data data, int sign)
{
	char	*tmp;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		if ((data.flags[1] == 1 || data.flags[2] == 1) && sign == 1)
		{
			tmp[0] = data.flags[1] == 1 ? '+' : ' ';
			(void)ft_strncpy(tmp + 1, str, ft_strlen(str));
		}
		else if (sign == -1)
		{
			tmp[0] = '-';
			(void)ft_strncpy(tmp + 1, str, ft_strlen(str));
		}
		else
			(void)ft_strncpy(tmp, str, ft_strlen(str));
	}
	else
		return (ft_prec_no_null(str, data, sign));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_print_prec(char *prec, t_data data, int sign)
{
	if (data.width <= (int)ft_strlen(prec))
		return (ft_no_width_prec(prec, data, sign));
	return (ft_no_prec(prec, data, sign));
}

char		*ft_prec(char *str, t_data data)
{
	char	*prec;
	char	*tmp;
	int		sign;

	sign = str[0] == '-' ? -1 : 1;
	if (str[0] == '-')
		tmp = ft_strdup(str + 1);
	else if (str[0] == '0')
		tmp = ft_strdup("");
	else
		tmp = ft_strdup(str);
	ft_strdel(&str);
	if (data.prec > (int)ft_strlen(tmp))
	{
		prec = ft_strnew(data.prec);
		ft_memset(prec, '0', data.prec);
		ft_strncpy(prec + data.prec - ft_strlen(tmp), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	else
		prec = tmp;
	return (ft_print_prec(prec, data, sign));
}
