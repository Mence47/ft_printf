/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:51:01 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 19:53:59 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_putstr_null(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	ft_putchar(s[i++]);
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return (i);
}

static char	*ft_prec_no_null(char *str, t_data data)
{
	char	*tmp;
	size_t	size;

	tmp = ft_strnew((size_t)data.width);
	ft_memset(tmp, ' ', (size_t)data.width);
	size = ft_strlen(str);
	if (size == 0)
		size = 1;
	ft_memcpy(tmp + data.width - size, str, size);
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_prec_no_minus(char *str, t_data data)
{
	char	*tmp;
	size_t	size;

	if (data.flags[4] == 1)
	{
		tmp = ft_strnew((size_t)data.width);
		ft_memset(tmp, '0', (size_t)data.width);
		size = ft_strlen(str);
		if (size == 0)
			size = 1;
		ft_strncpy(tmp + data.width - size, str, size);
	}
	else
		return (ft_prec_no_null(str, data));
	ft_strdel(&str);
	return (tmp);
}

static char	*ft_width(char *str, t_data data)
{
	char	*tmp;
	size_t	size;

	if (data.flags[0] == 1)
	{
		tmp = ft_strnew(data.width);
		(void)ft_memset(tmp, ' ', (size_t)data.width);
		size = ft_strlen(str);
		if (size == 0)
			size = 1;
		(void)ft_memcpy(tmp, str, size);
	}
	else
		return (ft_prec_no_minus(str, data));
	ft_strdel(&str);
	return (tmp);
}

int			ft_print_char(va_list ap, t_data data)
{
	char	*str;
	int		size;
	int		flag;

	if (data.length[2] == 1)
		str = ft_print_unicode_char(ap, &flag);
	else
	{
		str = ft_strnew(1);
		str[0] = (char)va_arg(ap, int);
		flag = str[0] == '\0' ? 1 : 0;
	}
	if (data.width > (int)ft_strlen(str))
		str = ft_width(str, data);
	if (flag == 1)
		size = ft_putstr_null(str);
	else
	{
		ft_putstr(str);
		size = (int)ft_strlen(str);
	}
	ft_strdel(&str);
	return (size);
}
