/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:59:32 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:35:53 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char					*ft_alloc_zero(int prec)
{
	char				*ptr;

	if (prec == -2)
	{
		ptr = ft_strnew(1);
		ft_memset(ptr, '0', 1);
	}
	else
	{
		ptr = ft_strnew((size_t)prec + 1);
		ft_memset(ptr, '0', (size_t)prec + 1);
	}
	return (ptr);
}

static char					*ft_itoa_u(unsigned long long n, int prec)
{
	char				*ptr;
	size_t				i;
	unsigned long long	result;

	if (n == 0)
		return (ft_alloc_zero(prec));
	result = n;
	ptr = ft_strnew(19 + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (result != 0)
	{
		ptr[i++] = (char)(result % 10 + '0');
		result /= 10;
		prec--;
	}
	while (prec-- > -1)
		ptr[i++] = '0';
	return (ft_strrev(ptr));
}

static unsigned long long	ft_find_prec(int prec)
{
	unsigned long long	result;

	if (prec == 0)
		return (1);
	result = 10;
	return (ft_find_prec(prec - 1) * result);
}

static char					*ft_itoa_f(double arg, t_data data)
{
	char				*str;
	unsigned long		integer;
	unsigned long		fraction;
	char				*tmp;
	double				mod_arg;

	mod_arg = arg < 0 ? arg * -1 : arg;
	integer = (uint64_t)mod_arg;
	str = ft_itoa_u(integer, -2);
	if (*((uint64_t*)&arg) >> 63 == 1)
	{
		tmp = ft_strjoin("-", str);
		ft_strdel(&str);
		str = tmp;
	}
	fraction = ft_find_prec(data.prec + 1);
	fraction = (unsigned long)((mod_arg - (long double)integer) * fraction);
	tmp = ft_strjoin(str, ".");
	ft_strdel(&str);
	str = tmp;
	tmp = ft_strjoin(str, ft_itoa_u(fraction, data.prec));
	ft_round(&tmp);
	ft_strdel(&str);
	return (tmp);
}

int							ft_print_float(va_list ap, t_data data)
{
	double				arg;
	char				*str;
	int					size;

	arg = va_arg(ap, double);
	if (data.prec == -1)
		data.prec = 6;
	str = ft_itoa_f(arg, data);
	str = ft_change_format_f(str, data);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
