/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:05:31 by ean               #+#    #+#             */
/*   Updated: 2021/11/12 11:20:30 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = 0;
	while (*dst && ret < dstsize)
	{
		++dst;
		++ret;
	}
	while (*src && ret + 1 < dstsize)
	{
		*dst++ = *src++;
		++ret;
	}
	if (ret < dstsize)
		*dst = '\0';
	while (*src++)
		++ret;
	return (ret);
}
