/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:49:14 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/13 11:51:32 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	draw_low(void *mlx_ptr, void *win_ptr, t_pmap *beg, t_pmap *end)
{
	int	dx;
	int	dy;
	int	yi;
	int	dd;

	yi = 1;
	dx = endx - begx;
	dy = endy - begy;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	dd = 2 * dy - dx;
	while (begx < endx)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, begx, begy, 65535); // call to a gradient function?
		if (dd > 0)
		{
			begy = begy + yi;
			dd = dd - 2 * dx;
		}
		dd = dd + 2 * dy;
		begx = begx + 1;
	}
}

static void	draw_high(void *mlx_ptr, void *win_ptr, t_pmap *beg, t_pmap *end)
{
	int	dx;
	int	dy;
	int	xi;
	int	dd;

	xi = 1;
	dx = endx - begx;
	dy = endy - begy;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	dd = 2 * dx - dy;
	while (begy < endy)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, begx, begy, 65535);
		if (dd > 0)
		{
			begx = begx + xi;
			dd = dd - 2 * dy;
		}
		dd = dd + 2 * dx;
		begy = begy + 1;
	}
}

void		draw_line(void *mlx_ptr, void *win_ptr, t_pmap *beg, t_pmap *end)
{
	if (abs(endy - begy) < abs(endx - begx))
	{
		if (begx > endx)
			draw_low(mlx_ptr, win_ptr, end, beg);
		else
			draw_low(mlx_ptr, win_ptr, beg, end);
	}
	else
	{
		if (begy > endy)
			draw_high(mlx_ptr, win_ptr, end, beg);
		else
			draw_high(mlx_ptr, win_ptr, beg, end);
	}
}
