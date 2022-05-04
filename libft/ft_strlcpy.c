/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:45:27 by ean               #+#    #+#             */
/*   Updated: 2021/11/12 11:20:34 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = 0;
	while (src[ret] && ret + 1 < dstsize)
	{
		dst[ret] = src[ret];
		++ret;
	}
	if (ret < dstsize)
		dst[ret] = '\0';
	while (src[ret])
		++ret;
	return (ret);
}
