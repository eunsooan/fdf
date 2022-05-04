/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:47:25 by ean               #+#    #+#             */
/*   Updated: 2022/03/17 13:58:53 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "parse.h"
#include "transform.h"
#include "draw.h"
#include "parse_utils.h"
#define ESC_KEY 53

static int	terminate(int keycode, t_vars *vars);

int	main(int argc, char *argv[])
{
	t_table	tab;
	t_vars	vars;
	t_img	img;

	plot_points_in_space(&tab, argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, IMAGE_WIDTH, IMAGE_HEIGHT, "ean's fdf");
	img.img = mlx_new_image(vars.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	transform_points_mandatory(&tab);
	draw_image(&img, &tab);
	free_points(&tab);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	mlx_key_hook(vars.win, terminate, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

static int	terminate(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
