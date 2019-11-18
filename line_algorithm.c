/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:49:14 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 11:49:54 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	draw_dx(t_mprop *mprop, t_pmap *beg, t_pmap *end)
{
	int		error;
	int		i;
	t_pcur	*pcur;

	pcur = (t_pcur *)malloc(sizeof(t_pcur));
	error = (mprop->dy) - mprop->dx;
	pcur->x = beg->ix + mprop->stpx;
	pcur->y = beg->iy;
	i = 1;
	mlx_pixel_put(PMLX, PWIN, beg->ix, beg->iy,
					get_color(mprop, beg, end, pcur));
	while (i <= mprop->dx)
	{
		if (error > 0)
		{
			error += (mprop->dy - mprop->dx);
			pcur->y += mprop->stpy;
		}
		else
			error += mprop->dy;
		mlx_pixel_put(PMLX, PWIN, pcur->x, pcur->y,
					get_color(mprop, beg, end, pcur));
		pcur->x += mprop->stpx;
		i++;
	}
}

static void	draw_dy(t_mprop *mprop, t_pmap *beg, t_pmap *end)
{
	int		error;
	int		i;
	t_pcur	*pcur;

	pcur = (t_pcur *)malloc(sizeof(t_pcur));
	error = (mprop->dx) - mprop->dy;
	pcur->y = beg->iy + mprop->stpy;
	pcur->x = beg->ix;
	i = 1;
	mlx_pixel_put(PMLX, PWIN, beg->ix, beg->iy,
					get_color(mprop, beg, end, pcur));
	while (i <= mprop->dy)
	{
		if (error > 0)
		{
			error += (mprop->dx - mprop->dy);
			pcur->x += mprop->stpx;
		}
		else
			error += mprop->dx;
		mlx_pixel_put(PMLX, PWIN, pcur->x, pcur->y,
					get_color(mprop, beg, end, pcur));
		pcur->y += mprop->stpy;
		i++;
	}
}

static int	ft_abs(int x)
{
	return (x > 0 ? x : -x);
}

void		draw_line(t_mprop *mprop, t_pmap *beg, t_pmap *end)
{
	mprop->dx = ft_abs(ENDX - BEGX);
	mprop->dy = ft_abs(ENDY - BEGY);
	mprop->stpx = ENDX >= BEGX ? 1 : -1;
	mprop->stpy = ENDY >= BEGY ? 1 : -1;
	if (mprop->dx > mprop->dy)
		draw_dx(mprop, beg, end);
	else
		draw_dy(mprop, beg, end);
}
