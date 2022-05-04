/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:11:04 by ean               #+#    #+#             */
/*   Updated: 2022/03/07 15:51:52 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned char	*ptr;
	size_t			byte_count;

	byte_count = count * size;
	ret = malloc(byte_count);
	if (ret == NULL)
		return (NULL);
	ptr = ret;
	while (byte_count--)
	{
		*ptr = 0;
		++ptr;
	}
	return (ret);
}
