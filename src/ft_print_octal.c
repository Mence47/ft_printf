/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:55:42 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 20:42:43 by rtroll           ###   ########.fr       */
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

char		*ft_itoa_o(size_t n)
{
	char				*ptr;
	size_t				i;
	unsigned long long	result;

	if (n == 0)
		return (ft_alloc_zero());
	result = n;
	ptr = ft_strnew(22);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (result != 0)
	{
		ptr[i++] = result % 8 + '0';
		result /= 8;
	}
	return (ft_strrev(ptr));
}

int			ft_print_octal(va_list ap, t_data data)
{
	unsigned long long	arg;
	char				*str;
	int					size;

	arg = va_arg(ap, unsigned long long);
	if (data.length[0] == 1)
		str = ft_itoa_o((unsigned char)arg);
	else if (data.length[1] == 1)
		str = ft_itoa_o((unsigned short int)arg);
	else if (data.length[2] == 1)
		str = ft_itoa_o((unsigned long int)arg);
	else if (data.length[3] == 1)
		str = ft_itoa_o(arg);
	else if (data.length[5] == 1)
		str = ft_itoa_o((uintmax_t)arg);
	else if (data.length[6] == 1)
		str = ft_itoa_o(arg);
	else
		str = ft_itoa_o((unsigned int)arg);
	str = ft_change_format_o(str, data);
	ft_putstr(str);
	size = (int)ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
