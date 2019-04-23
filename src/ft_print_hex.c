/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:57:16 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 20:28:54 by rtroll           ###   ########.fr       */
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

char		*ft_itoa_h(size_t n)
{
	char				*ptr;
	size_t				i;
	unsigned long long	result;

	if (n == 0)
		return (ft_alloc_zero());
	result = n;
	ptr = ft_strnew(18);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (result != 0)
	{
		ptr[i++] = result % 16 + (result % 16 >= 10 ? 'a' - 10 : '0');
		result /= 16;
	}
	return (ft_strrev(ptr));
}

int			ft_print_hex(va_list ap, t_data data)
{
	size_t				arg;
	char				*str;
	int					size;

	arg = va_arg(ap, size_t);
	if (data.length[0] == 1)
		str = ft_itoa_h((unsigned char)arg);
	else if (data.length[1] == 1)
		str = ft_itoa_h((unsigned short int)arg);
	else if (data.length[2] == 1)
		str = ft_itoa_h((unsigned long int)arg);
	else if (data.length[3] == 1)
		str = ft_itoa_h((unsigned long long)arg);
	else if (data.length[5] == 1)
		str = ft_itoa_h((uintmax_t)arg);
	else if (data.length[6] == 1)
		str = ft_itoa_h(arg);
	else
		str = ft_itoa_h((unsigned int)arg);
	str = ft_change_format_h(str, data);
	ft_putstr(str);
	size = (int)ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
