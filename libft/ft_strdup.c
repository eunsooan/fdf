/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:24:55 by ean               #+#    #+#             */
/*   Updated: 2021/11/16 14:07:46 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;
	char	*p;

	len = 0;
	while (s1[len])
		++len;
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (ret)
	{
		p = ret;
		while (*s1)
			*p++ = *s1++;
		*p = '\0';
	}
	return (ret);
}
