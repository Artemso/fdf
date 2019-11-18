/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:11:14 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 14:29:08 by asolopov         ###   ########.fr       */
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

/*
** Set initial colors depending on relative Z position
*/

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
	return ((1 - percent) * start + percent * end);
}

/*
** Calculate color for gradient using bit ops
*/

int		get_color(t_mprop *mprop, t_pmap *beg, t_pmap *end, t_pcur *pcur)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (beg->color == end->color)
		return (end->color);
	if (mprop->dx > mprop->dy)
		percent = percentage(BEGX, ENDX, pcur->x);
	else
		percent = percentage(BEGY, ENDY, pcur->y);
	red = get_light((BEGC >> 16) & 255, (ENDC >> 16) & 255, percent);
	green = get_light((BEGC >> 8) & 255, (ENDC >> 8) & 255, percent);
	blue = get_light(BEGC & 255, ENDC & 255, percent);
	return ((red << 16) | (green << 8) | (blue));
}
