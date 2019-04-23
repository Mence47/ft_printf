/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:43:57 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 21:04:28 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_four_bytes(unsigned int arg)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = (char)((arg >> 18) | 0b11110000);
	str[1] = (char)(((arg >> 12) & 0b00111111) | 0b10000000);
	str[2] = (char)(((arg >> 6) & 0b00111111) | 0b10000000);
	str[3] = (char)((arg & 0b00111111) | 1 << 7);
	return (str);
}

static char	*ft_make_wchar(unsigned int arg)
{
	char			*str;

	if (arg <= 0x7f)
	{
		str = ft_strnew(1);
		str[0] = (char)arg;
	}
	else if (arg <= 0x07ff)
	{
		str = ft_strnew(2);
		str[0] = (char)((arg >> 6) | 0b11000000);
		str[1] = (char)((arg & 0b00111111) | 1 << 7);
	}
	else if (arg <= 0xffff)
	{
		str = ft_strnew(3);
		str[0] = (char)((arg >> 12) | 0b11100000);
		str[1] = (char)(((arg >> 6) & 0b00111111) | 0b10000000);
		str[2] = (char)((arg & 0b00111111) | 1 << 7);
	}
	else
		return (ft_four_bytes(arg));
	return (str);
}

char		*ft_print_unicode_char(va_list ap, int *flag)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	*flag = arg == 0 ? 1 : 0;
	return (ft_make_wchar(arg));
}

static char	*ft_print_no_null(unsigned int *arg, t_data d)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = ft_strnew(0);
	tmp2 = NULL;
	while (*arg != 0)
	{
		tmp = ft_make_wchar(*arg);
		if (d.prec >= (int)ft_strlen(str) + (int)ft_strlen(tmp) || d.prec == -1)
		{
			tmp2 = str;
			str = ft_strjoin(str, tmp);
		}
		else
		{
			ft_strdel(&tmp2);
			ft_strdel(&tmp);
			break ;
		}
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
		arg++;
	}
	return (str);
}

char		*ft_print_unicode_str(va_list ap, t_data data)
{
	char			*str;
	char			*tmp;
	unsigned int	*arg;

	arg = va_arg(ap, unsigned int *);
	if (arg == NULL)
	{
		str = ft_strdup("(null)");
		if (data.prec < (int)ft_strlen(str) && data.prec != -1)
		{
			tmp = ft_strnew(data.prec);
			ft_memcpy(tmp, str, data.prec);
			ft_strdel(&str);
			str = tmp;
		}
		return (str);
	}
	return (ft_print_no_null(arg, data));
}
