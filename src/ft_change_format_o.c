/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_format_o.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:38:14 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 20:41:06 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_prec_no_null(char *str, t_data data)
{
	char		*tmp;
	char		*tmp2;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	if (data.flags[3] == 1 && str[0] != '0')
	{
		tmp2 = ft_strjoin("0", str);
		ft_strdel(&str);
		str = tmp2;
	}
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
	char		*tmp2;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		if (data.flags[3] == 1 && str[0] != '0')
		{
			tmp2 = ft_strjoin("0", str);
			ft_strdel(&str);
			str = tmp2;
		}
		(void)ft_strncpy(tmp, str, ft_strlen(str));
	}
	else
		return (ft_prec_no_minus(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_width_prec(char *str, t_data data)
{
	char	*tmp;

	if (data.flags[3] == 1 && str[0] != '0')
	{
		tmp = ft_strjoin("0", str);
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}

char		*ft_change_format_o(char *str, t_data data)
{
	if (data.prec == -1 && data.width <= (int)ft_strlen(str))
		return (ft_no_width_prec(str, data));
	if (data.prec == -1 && data.width > (int)ft_strlen(str))
		return (ft_no_prec(str, data));
	return (ft_prec_o(str, data));
}
