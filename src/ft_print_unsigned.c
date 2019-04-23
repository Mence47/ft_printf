/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:56:32 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 21:43:49 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_alloc_zero(void)
{
	char				*ptr;

	ptr = ft_strnew(1);
	ptr[0] = '0';
	return (ptr);
}

static char	*ft_itoa_u(size_t n)
{
	char				*ptr;
	size_t				i;
	unsigned long long	result;

	if (n == 0)
		return (ft_alloc_zero());
	result = n;
	ptr = ft_strnew(19 + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (result != 0)
	{
		ptr[i++] = result % 10 + '0';
		result /= 10;
	}
	return (ft_strrev(ptr));
}

int			ft_print_unsigned(va_list ap, t_data data)
{
	size_t				arg;
	char				*str;
	int					size;

	arg = va_arg(ap, size_t);
	if (data.length[0] == 1)
		str = ft_itoa_u((unsigned char)arg);
	else if (data.length[1] == 1)
		str = ft_itoa_u((unsigned short int)arg);
	else if (data.length[2] == 1)
		str = ft_itoa_u((unsigned long int)arg);
	else if (data.length[3] == 1)
		str = ft_itoa_u((unsigned long long)arg);
	else if (data.length[5] == 1)
		str = ft_itoa_u((uintmax_t)arg);
	else if (data.length[6] == 1)
		str = ft_itoa_u(arg);
	else
		str = ft_itoa_u((unsigned int)arg);
	str = ft_change_format_u(str, data);
	ft_putstr(str);
	size = (int)ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
