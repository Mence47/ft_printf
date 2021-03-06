/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:25:03 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:39:39 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_prec_no_null(char *str, t_data data)
{
	char	*tmp;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	ft_strncpy(tmp + data.width - ft_strlen(str), str, ft_strlen(str));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_no_prec(char *str, t_data data)
{
	char	*tmp;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		(void)ft_strncpy(tmp, str, ft_strlen(str));
	}
	else
		return (ft_prec_no_null(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_print_prec(char *prec, t_data data)
{
	if (data.width <= (int)ft_strlen(prec))
		return (prec);
	return (ft_no_prec(prec, data));
}

char		*ft_prec_u(char *str, t_data data)
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
