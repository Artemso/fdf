/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:26:02 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 19:20:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void		get_conic(t_mprop *mprop)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			PMAP->ix = mprop->strtx + (PMAPX) * mprop->zoom;
			PMAP->iy = mprop->strty + (PMAPY) * mprop->zoom;
			PMAP->color = set_color(mprop, PMAP);
			cx++;
		}
		cy++;
	}
	draw_picture(mprop);
}

void		get_iso(t_mprop *mprop)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			PMAP->ix = mprop->strtx +
				((PMAPX - PMAPY) * cos(0.523599)) * mprop->zoom;
			PMAP->iy = mprop->strty +
				(-PMAPZ * mprop->zmod) + ((PMAPX + PMAPY)
								* sin(0.523599)) * mprop->zoom;
			PMAP->color = set_color(mprop, PMAP);
			cx++;
		}
		cy++;
	}
	draw_picture(mprop);
}

void		get_perspective(t_mprop *mprop, t_eye *eye)
{
	int	cx;
	int	cy;

	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			PMAP->ix = mprop->strtx + ((eye->ez * (PMAPX - eye->ex)) /
					(eye->ez + (PMAPZ * mprop->zmod)) + eye->ex) * mprop->zoom;
			PMAP->iy = mprop->strty + ((eye->ez * (PMAPY - eye->ey)) /
					(eye->ez + (PMAPZ * mprop->zmod)) + eye->ey) * mprop->zoom;
			PMAP->color = set_color(mprop, PMAP);
			cx++;
		}
		cy++;
	}
	draw_picture(mprop);
}
