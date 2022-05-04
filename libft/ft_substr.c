/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:14:21 by ean               #+#    #+#             */
/*   Updated: 2021/11/16 14:22:08 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*malloc_sub(char const *s, unsigned int start, size_t *len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = malloc_sub(s, start, &len);
	if (ret)
	{
		i = 0;
		while (i < len && s[start + i])
		{
			ret[i] = s[start + i];
			++i;
		}
		ret[i] = '\0';
	}
	return (ret);
}

static char	*malloc_sub(char const *s, unsigned int start, size_t *len)
{
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		++s_len;
	if (start >= s_len)
		*len = 0;
	else if (s_len - start < *len)
		*len = s_len - start;
	return ((char *)malloc(sizeof(char) * (*len + 1)));
}
