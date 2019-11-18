/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:26:02 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 10:49:38 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	draw_picture(t_mprop *mprop)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			if (cx != mprop->width - 1)
				draw_line(mprop, mprop->map[cy][cx], mprop->map[cy][cx + 1]);
			if (cy != mprop->nlines - 1)
				draw_line(mprop, mprop->map[cy][cx], mprop->map[cy + 1][cx]);
			cx++;
		}
		cy++;
	}
}

void	get_conic(t_mprop *mprop)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			pmap->ix = mprop->strtx + (pmap_x) * mprop->zoom;
			pmap->iy = mprop->strty + (pmap_y) * mprop->zoom;
			pmap->color = set_color(mprop, pmap);
			cx++;
		}
		cy++;
	}
	draw_picture(mprop);
}

void	get_iso(t_mprop *mprop)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			pmap->ix = mprop->strtx + ((pmap_x - pmap_y) * cos(0.523599)) * mprop->zoom;
			pmap->iy = mprop->strty + (-pmap_z * mprop->zmod) + ((pmap_x  + pmap_y) * sin(0.523599)) * mprop->zoom;
			pmap->color = set_color(mprop, pmap);
			cx++;
		}
		cy++;
	}
	draw_picture(mprop);
}

void	get_perspective(t_mprop *mprop, t_eye *eye)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			pmap->ix = mprop->strtx + ((eye->ez * (pmap_x - eye->ex)) / (eye->ez + (pmap_z * mprop->zmod)) + eye->ex) * mprop->zoom;
			pmap->iy = mprop->strty + ((eye->ez * (pmap_y - eye->ey)) / (eye->ez + (pmap_z * mprop->zmod)) + eye->ey) * mprop->zoom;
			pmap->color = set_color(mprop, pmap);
			cx++;
		}
		cy++;
	}
	draw_picture(mprop);
}
