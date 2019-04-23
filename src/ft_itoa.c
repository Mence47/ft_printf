/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:52:03 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/04 14:08:37 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_max_min(long long *sign, char *ptr, long long *result)
{
	*sign = -1;
	*ptr = '8';
	*result = 922337203685477580;
}

static char	*ft_alloc_zero(void)
{
	char	*ptr;

	ptr = ft_strnew(1);
	ptr[0] = '0';
	return (ptr);
}

char		*ft_itoa(long long n)
{
	char		*ptr;
	size_t		i;
	long long	sign;
	long long	result;

	if (n == 0)
		return (ft_alloc_zero());
	i = 0;
	ptr = ft_strnew(19 + 1);
	result = n;
	sign = n;
	if (result < -9223372036854775807)
		ft_max_min(&sign, &ptr[i++], &result);
	else if (result < 0)
		result = result * -1;
	if (ptr == NULL)
		return (NULL);
	while (result != 0)
	{
		ptr[i++] = result % 10 + '0';
		result /= 10;
	}
	if (sign < 0)
		ptr[i++] = '-';
	return (ft_strrev(ptr));
}
