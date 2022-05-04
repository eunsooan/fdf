/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:38:53 by ean               #+#    #+#             */
/*   Updated: 2021/11/12 11:20:57 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	end = start;
	while (s1[end])
		++end;
	if (end > start)
		while (ft_strchr(set, s1[end - 1]))
			--end;
	ret = (char *)malloc(sizeof(*ret) * (end - start + 1));
	if (ret)
		ft_strlcpy(ret, &s1[start], end - start + 1);
	return (ret);
}
