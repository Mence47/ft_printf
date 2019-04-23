/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:25:47 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:39:21 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_prec_no_null(char *str, t_data data)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	tmp2 = ft_strjoin("0x", str);
	ft_strdel(&str);
	str = tmp2;
	ft_strncpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_prec(char *str, t_data data)
{
	char	*tmp;
	char	*tmp2;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		tmp2 = ft_strjoin("0x", str);
		ft_strdel(&str);
		str = tmp2;
		(void)ft_strncpy(tmp, str, ft_strlen(str));
	}
	else
		return (ft_prec_no_null(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_width_prec(char *str)
{
	char	*tmp;

	tmp = ft_strjoin("0x", str);
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_print_prec(char *prec, t_data data)
{
	if (data.width <= (int)ft_strlen(prec))
		return (ft_no_width_prec(prec));
	return (ft_no_prec(prec, data));
}

char		*ft_prec_p(char *str, t_data data)
{
	char	*prec;
	char	*tmp;

	if (str[0] == '0' && data.prec == 0)
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
	return (ft_print_prec(prec, data));
}
