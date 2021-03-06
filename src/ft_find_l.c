/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:30:35 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 21:38:16 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_find_l(char *sub, t_data *data)
{
	int	i;

	i = 0;
	while (sub[i])
	{
		if (sub[i] == 'l' && (i == 0 || sub[i - 1] != 'l')
				&& sub[i + 1] != 'l')
		{
			data->length[2] = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
