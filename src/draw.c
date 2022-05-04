/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:54:53 by ean               #+#    #+#             */
/*   Updated: 2022/03/16 13:48:50 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "draw_utils.h"

static void	draw_line(t_img *img, const t_point *p0, const t_point *p1);
static void	draw_line_low(t_img *img, const t_point *p0, const t_point *p1);
static void	draw_line_high(t_img *img, const t_point *p0, const t_point *p1);
static void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	draw_image(t_img *img, const t_table *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->row_size - 1)
	{
		j = tab->column_size - 1;
		while (j > 0)
		{
			draw_line(img, &tab->points[i][j], &tab->points[i][j - 1]);
			draw_line(img, &tab->points[i][j], &tab->points[i + 1][j - 1]);
			draw_line(img, &tab->points[i][j], &tab->points[i + 1][j]);
			--j;
		}
		draw_line(img, &tab->points[i][j], &tab->points[i + 1][j]);
		++i;
	}
	j = tab->column_size - 1;
	while (j > 0)
	{
		draw_line(img, &tab->points[i][j], &tab->points[i][j - 1]);
		--j;
	}
}

static void	draw_line(t_img *img, const t_point *p0, const t_point *p1)
{
	if (abs(p1->x - p0->x) >= abs(p1->y - p0->y))
	{
		if (p0->x > p1->x)
			draw_line_low(img, p1, p0);
		else
			draw_line_low(img, p0, p1);
	}
	else
	{
		if (p0->y > p1->y)
			draw_line_high(img, p1, p0);
		else
			draw_line_high(img, p0, p1);
	}
}

static void	draw_line_low(t_img *img, const t_point *p0, const t_point *p1)
{
	int		da;
	int		db;
	int		determinant;
	int		move;
	t_point	p;

	da = abs(p1->x - p0->x);
	db = abs(p1->y - p0->y);
	determinant = (db << 1) - da;
	move = (p1->y >= p0->y) - (p1->y < p0->y);
	p = *(t_point *)p0;
	while (p.x < p1->x)
	{
		my_mlx_pixel_put(img, p.x, p.y, p.color.color);
		determinant += db << 1;
		if (determinant >= 0)
		{
			determinant -= da << 1;
			p.y += move;
		}
		++p.x;
		color_update(&p, p0, p1);
	}
}

static void	draw_line_high(t_img *img, const t_point *p0, const t_point *p1)
{
	int		da;
	int		db;
	int		determinant;
	int		move;
	t_point	p;

	da = abs(p1->y - p0->y);
	db = abs(p1->x - p0->x);
	determinant = (db << 1) - da;
	move = (p1->x >= p0->x) - (p1->x < p0->x);
	p = *(t_point *)p0;
	while (p.y < p1->y)
	{
		my_mlx_pixel_put(img, p.x, p.y, p.color.color);
		determinant += db << 1;
		if (determinant >= 0)
		{
			determinant -= da << 1;
			p.x += move;
		}
		++p.y;
		color_update(&p, p0, p1);
	}
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
