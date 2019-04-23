/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:53:12 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:41:04 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

static char	*ft_prec_no_null(char *str, t_data data)
{
	char			*tmp;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	ft_memcpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_prec_no_minus(char *str, t_data data)
{
	char			*tmp;

	if (data.flags[4] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		ft_memset(tmp, '0', (size_t)data.width);
		ft_memcpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	}
	else
		return (ft_prec_no_null(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_prec(char *str, t_data data)
{
	char			*tmp;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		(void)ft_memcpy(tmp, str, ft_strlen(str));
	}
	else
		return (ft_prec_no_minus(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_change_format_s(char *str, t_data data)
{
	if (data.width <= (int)ft_strlen(str))
		return (str);
	if (data.width > (int)ft_strlen(str))
		return (ft_no_prec(str, data));
	return (NULL);
}

int			ft_print_string(va_list ap, t_data data)
{
	char			*str;
	int				size;
	char			*arg;

	if (data.length[2] == 1)
		str = ft_print_unicode_str(ap, data);
	else
	{
		arg = va_arg(ap, char *);
		str = ft_print_regular_string(&data, arg);
	}
	str = ft_change_format_s(str, data);
	ft_putstr(str);
	size = (int)ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
