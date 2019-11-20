/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:11:14 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/20 16:08:10 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_percent(int zmin, int zmax, int zcurr)
{
	double	position;
	double	len;

	position = zcurr - zmin;
	len = zmax - zmin;
	if (len == 0)
		return (1.0);
	else
		return (position / len);
}

/*
** Set initial colors depending on relative Z position
*/

int		set_color(t_mprop *mprop, t_pmap *curr)
{
	double percent;

	percent = get_percent(mprop->zmin, mprop->zmax, curr->z * mprop->zmod);
	if (percent < 0.1)
		return (mprop->palette == 1 ? BOTTOM : BOTTOM2);
	else if (percent < 0.3)
		return (mprop->palette == 1 ? LOWER : LOWER2);
	else if (percent < 0.7)
		return (mprop->palette == 1 ? MIDDLE : MIDDLE2);
	else
		return (mprop->palette == 1 ? TOP : TOP2);
}

int		get_weight(int begc, int endc, double percent)
{
	return (percent * endc + (1 - percent) * begc);
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
		percent = get_percent(BEGX, ENDX, pcur->x);
	else
		percent = get_percent(BEGY, ENDY, pcur->y);
	red = get_weight((BEGC >> 16) & 255, (ENDC >> 16) & 255, percent);
	green = get_weight((BEGC >> 8) & 255, (ENDC >> 8) & 255, percent);
	blue = get_weight(BEGC & 255, ENDC & 255, percent);
	return ((red << 16) | (green << 8) | (blue));
}
