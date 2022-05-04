/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:10:34 by ean               #+#    #+#             */
/*   Updated: 2021/11/16 14:04:02 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	needle_len = 0;
	while (needle[needle_len])
		++needle_len;
	if (needle_len == 0)
		return ((char *)haystack);
	if (*haystack)
	{
		i = 0;
		while (i + needle_len <= len)
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j])
				++j;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
			++i;
		}
	}
	return (NULL);
}
