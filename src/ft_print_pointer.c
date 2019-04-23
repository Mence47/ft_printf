/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:54:00 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:35:26 by rtroll           ###   ########.fr       */
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

static char	*ft_itoa_h(unsigned long long n)
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

int			ft_print_pointer(va_list ap, t_data data)
{
	unsigned long long	arg;
	char				*str;
	int					size;

	arg = va_arg(ap, unsigned long long int);
	str = ft_itoa_h(arg);
	str = ft_change_format_p(str, data);
	ft_putstr(str);
	size = (int)ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
