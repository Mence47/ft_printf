/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:23:24 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 19:23:36 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_check_point(char *sub, int i)
{
	i--;
	while (sub[i] == '0' && i > 0)
	{
		i--;
	}
	if (sub[i] == '.')
		return (0);
	return (1);
}

int	ft_check_point_null(char *sub)
{
	int	i;

	i = 0;
	while (sub[i] == '0' && sub[i])
		i++;
	if (ft_isdigit(sub[i]) == 0)
		return (1);
	return (0);
}

int	ft_check_null(char *sub)
{
	while (*sub)
		if (*sub++ != '0')
			return (1);
	return (0);
}
