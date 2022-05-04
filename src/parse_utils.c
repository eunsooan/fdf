/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:05 by ean               #+#    #+#             */
/*   Updated: 2022/03/17 14:32:14 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse_utils.h"
#include "../libft/libft.h"
#include "utils.h"

unsigned int	read_color(const char *str)
{
	const char		*ptr;
	unsigned int	color;

	ptr = ft_strchr(str, ',');
	if (ptr == NULL)
		return (0x00FFFFFF);
	ptr += 3;
	color = 0;
	while (*ptr != '\0')
	{
		color *= 16;
		if (ft_isdigit(*(char *)ptr))
			color += *ptr - '0';
		else if ('a' <= *ptr && *ptr <= 'f')
			color += *ptr - 'a' + 10;
		else if ('A' <= *ptr && *ptr <= 'F')
			color += *ptr - 'A' + 10;
		else
			break ;
		++ptr;
	}
	return (color);
}

int	product_overflows(const int a, const int b)
{
	int	product;

	product = a * b;
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (product <= 0)
			return (1);
	}
	else if ((a > 0 && b < 0) || (a < 0 && b > 0))
	{
		if (product >= 0)
			return (1);
	}
	return (0);
}

void	free_points(t_table *tab)
{
	int	i;

	i = 0;
	while (i < tab->row_size)
	{
		free(tab->points[i]);
		++i;
	}
	free(tab->points);
}

void	copy_table(t_table *dst, const t_table *src)
{
	size_t	byte_count;
	int		i;

	dst->row_size = src->row_size;
	dst->column_size = src->column_size;
	dst->points = malloc(sizeof(*dst->points) * dst->row_size);
	if (dst->points == NULL)
		exit_with_message("copy_table()'s malloc failed");
	i = 0;
	byte_count = sizeof(t_table) * dst->column_size;
	while (i < dst->row_size)
	{
		dst->points[i] = malloc(byte_count);
		if (dst->points[i] == NULL)
			exit_with_message("copy_table()'s malloc failed");
		ft_memcpy(dst->points[i], src->points[i], byte_count);
		++i;
	}
}
