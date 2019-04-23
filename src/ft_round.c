/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:57:23 by rtroll            #+#    #+#             */
/*   Updated: 2019/01/15 22:00:09 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_finish_round(char **str, size_t i)
{
	char		*tmp;

	while (i > 0)
	{
		if (str[0][i] > '9')
		{
			str[0][i--] = '0';
			str[0][i] += 1;
		}
		else
			break ;
	}
	if (str[0][0] > '9')
	{
		tmp = ft_strjoin("1", *str);
		tmp[1] = '0';
		ft_strdel(str);
		*str = tmp;
	}
	str[0][ft_strlen(*str) - 1] = '\0';
	return (1);
}

static int	ft_round_null(char **str, size_t i)
{
	if (str[0][i + 1] < '5')
	{
		str[0][i] = '\0';
		return (1);
	}
	str[0][--i] += 1;
	str[0][ft_strlen(*str) - 1] = '\0';
	return (ft_finish_round(str, i));
}

int			ft_round(char **str)
{
	size_t		i;

	i = ft_strlen(*str) - 2;
	if (str[0][i] == '.')
		return (ft_round_null(str, i));
	while (str[0][i] != '.')
	{
		if (str[0][i + 1] >= '5')
		{
			str[0][i] += 1;
			str[0][i + 1] = '0';
			if (str[0][i] <= '9')
				break ;
		}
		else if (i == ft_strlen(*str) - 2)
			break ;
		i--;
	}
	if (str[0][i + 1] > '9')
	{
		str[0][i-- + 1] = '0';
		str[0][i] += 1;
	}
	return (ft_finish_round(str, i));
}
