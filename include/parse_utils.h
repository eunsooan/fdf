/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:27:28 by ean               #+#    #+#             */
/*   Updated: 2022/03/13 16:27:48 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H
# include "parse.h"

unsigned int	read_color(const char *str);
int				product_overflows(const int a, const int b);
void			free_points(t_table *tab);
void			copy_table(t_table *dst, const t_table *src);

#endif
