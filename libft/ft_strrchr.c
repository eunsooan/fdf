/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:30:17 by ean               #+#    #+#             */
/*   Updated: 2021/11/19 10:55:09 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s0;
	char		ch;

	s0 = s;
	while (*s)
		++s;
	ch = c;
	while (s >= s0)
	{
		if (*s == ch)
			return ((char *)s);
		--s;
	}
	return (NULL);
}
