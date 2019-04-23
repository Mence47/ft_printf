/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:44:00 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/17 15:55:40 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_in_spec(char c)
{
	int		i;
	char	*spec;

	i = 0;
	spec = ft_strdup("cCsSpdDioOuUxXf%");
	while ((size_t)i < ft_strlen(spec))
	{
		if (c == spec[i])
		{
			ft_strdel(&spec);
			return (1);
		}
		i++;
	}
	ft_strdel(&spec);
	return (0);
}

static int	ft_in_other(char c)
{
	int		i;
	char	*spec;

	i = 0;
	spec = ft_strdup("hlL-+ #0.jz");
	while ((size_t)i < ft_strlen(spec))
	{
		if (c == spec[i] || ft_isdigit(c))
		{
			ft_strdel(&spec);
			return (1);
		}
		i++;
	}
	ft_strdel(&spec);
	return (0);
}

static int	ft_find_substring(const char *frt, char **sub)
{
	int	i;

	i = 0;
	while (ft_in_spec(frt[i]) == 0)
	{
		if (frt[i] == '\0')
			return (i + 1);
		if (ft_in_other(frt[i]) == 0)
			break ;
		i++;
	}
	*sub = ft_strsub(frt, 0, (i + 1));
	return (i + 2);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	char	*sub;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	sub = NULL;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i++]);
			count++;
		}
		else
		{
			i += ft_find_substring(&format[i + 1], &sub);
			count += ft_print_sub(ap, sub);
			ft_strdel(&sub);
		}
	}
	va_end(ap);
	return (count);
}
