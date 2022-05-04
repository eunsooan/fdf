/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:52:44 by ean               #+#    #+#             */
/*   Updated: 2021/11/12 11:19:58 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static bool	overlap(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst != src)
	{
		d = dst;
		s = src;
		if (overlap(dst, src, len))
		{
			d += len - 1;
			s += len - 1;
			while (len--)
				*d-- = *s--;
		}
		else
			while (len--)
				*d++ = *s++;
	}
	return (dst);
}

static bool	overlap(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	size_t				i;

	s = src;
	i = 1;
	while (i < len)
	{
		if (s + i == dst)
			return (true);
		++i;
	}
	return (false);
}
