/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:11:14 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 11:06:03 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

double	percentage(int beg, int end, int curr)
{
	double	place;
	double	size;

	place = curr - beg;
	size = end - beg;
	return ((size == 0) ? 1.0 : (place / size));
}

int		set_color(t_mprop *mprop, t_pmap *curr)
{
	double percent;

	percent = percentage(mprop->zmin, mprop->zmax, curr->z * mprop->zmod);
	if (percent < 0.1)
		return (BOTTOM);
	else if (percent < 0.3)
		return (LOWER);
	else if (percent < 0.7)
		return (MIDDLE);
	else
		return (TOP);
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		get_color(t_mprop *mprop, t_pmap *beg, t_pmap *end, t_pcur *pcur)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (beg->color == end->color)
		return (end->color);
	if (mprop->dx > mprop->dy)
		percent = percentage(begx, endx, pcur->x);
	else
		percent = percentage(begy, endy, pcur->y);
	red = get_light((beg->color >> 16) & 255, (end->color >> 16) & 255, percent);
	green = get_light((beg->color >> 8) & 255, (end->color >> 8) & 255, percent);
	blue = get_light(beg->color & 255, end->color & 255, percent);
	return ((red << 16) | (green << 8) | (blue));
}
