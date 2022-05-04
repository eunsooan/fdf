/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:57:44 by ean               #+#    #+#             */
/*   Updated: 2022/03/17 13:57:44 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils.h"

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	color_update(t_point *p, const t_point *p0, const t_point *p1)
{
	int	da;
	int	dr;
	int	dg;
	int	db;
	int	step;

	if (abs(p1->x - p0->x) < abs(p1->y - p0->y))
	{
		da = abs(p1->y - p0->y);
		step = abs(p->y - p0->y);
	}
	else
	{
		da = abs(p1->x - p0->x);
		step = abs(p->x - p0->x);
	}
	dr = (int)p1->color.trgb[2] - (int)p0->color.trgb[2];
	dg = (int)p1->color.trgb[1] - (int)p0->color.trgb[1];
	db = (int)p1->color.trgb[0] - (int)p0->color.trgb[0];
	p->color.trgb[2] = p0->color.trgb[2] + (dr * step) / da;
	p->color.trgb[1] = p0->color.trgb[1] + (dg * step) / da;
	p->color.trgb[0] = p0->color.trgb[0] + (db * step) / da;
}
