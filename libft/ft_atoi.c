/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:17:51 by ean               #+#    #+#             */
/*   Updated: 2021/11/16 16:25:40 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#define POSITIVE -1
#define NEGATIVE 1

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		++str;
	sign = POSITIVE;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = NEGATIVE;
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (ret < 10 * ret - (*str - '0'))
		{
			if (sign == POSITIVE)
				return ((int)LONG_MAX);
			return ((int)LONG_MIN);
		}
		ret = 10 * ret - (*str++ - '0');
	}
	return (sign * ret);
}
