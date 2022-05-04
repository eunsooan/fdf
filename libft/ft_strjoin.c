/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:22:07 by ean               #+#    #+#             */
/*   Updated: 2021/11/11 09:23:00 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_stpcpy(char *dst, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*end;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret)
	{
		end = ft_stpcpy(ret, s1);
		ft_stpcpy(end, s2);
	}
	return (ret);
}

static char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
