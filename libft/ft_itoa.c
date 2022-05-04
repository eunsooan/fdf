/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:53:49 by ean               #+#    #+#             */
/*   Updated: 2021/11/16 17:57:36 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*str_malloc(int n);
static void	ft_strrev(char *s);

char	*ft_itoa(int n)
{
	char	*ret;
	int		sign;
	int		i;

	ret = str_malloc(n);
	if (ret)
	{
		sign = 1;
		if (n < 0)
			sign = -1;
		i = 0;
		ret[i++] = sign * (n % 10) + '0';
		n /= 10;
		while (n)
		{
			ret[i++] = sign * (n % 10) + '0';
			n /= 10;
		}
		if (sign < 0)
			ret[i++] = '-';
		ret[i] = '\0';
		ft_strrev(ret);
	}
	return (ret);
}

static char	*str_malloc(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		++len;
	n /= 10;
	while (n)
	{
		++len;
		n /= 10;
	}
	return ((char *)malloc(sizeof(char) * (len + 1)));
}

static void	ft_strrev(char *s)
{
	int		i;
	int		len;
	char	temp;

	len = 0;
	while (s[len])
		++len;
	i = 0;
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		++i;
	}
}
