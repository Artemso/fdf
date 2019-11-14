/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:49:14 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/14 15:42:18 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	draw_dx(t_mprop *mprop, t_pmap *beg)
{
	int	error;
	int	i;
	int	x;
	int	y;

	error = (mprop->dy << 1) - mprop->dx;
	x = beg->ix + mprop->stpx;
	y = beg->iy;
	i = 1;
	mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, beg->ix, beg->iy, 16737535);
	while (i <= mprop->dx)
	{
		if (error > 0)
		{
			error += (mprop->dy - mprop->dx) << 1;
			y += mprop->stpy;
		}
		else
			error += mprop->dy << 1;
		mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, x, y, 16737535);
		x += mprop->stpx;
		i++;
	}
}

static void	draw_dy(t_mprop *mprop, t_pmap *beg)
{
	int	error;
	int	i;
	int	x;
	int	y;

	error = (mprop->dx << 1) - mprop->dy;
	y = beg->iy + mprop->stpy;
	x = beg->ix;
	i = 1;
	mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, beg->ix, beg->iy, 16737535);
	while (i <= mprop->dy)
	{
		if (error > 0)
		{
			error += (mprop->dx - mprop->dy) << 1;
			x += mprop->stpx;
		}
		else
			error += mprop->dx << 1;
		mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, x, y, 16737535);
		y += mprop->stpy;
		i++;
	}
}

void		draw_line(t_mprop *mprop, t_pmap *beg, t_pmap *end)
{

	mprop->dx = abs(endx - begx);
	mprop->dy = abs(endy - begy);
	mprop->stpx = endx >= begx ? 1 : -1;
	mprop->stpy = endy >= begy ? 1 : -1;
	if (mprop->dx > mprop->dy)
		draw_dx(mprop, beg);
	else
		draw_dy(mprop, beg);
}
