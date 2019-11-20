/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:56:03 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/20 16:05:12 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		reset_mprop(t_mprop *mprop)
{
	mprop->zoom = 15;
	mprop->zmod = 2;
	mprop->strtx = MAP_WID / 4;
	mprop->strty = MAP_LEN / 4;
	mprop->eye->ex = -500;
	mprop->eye->ey = -500;
	mprop->eye->ez = 4000;
}

static void	init_mprop(t_mprop *mprop)
{
	mprop->palette = 0;
	mprop->initwidth = 0;
	mprop->nlines = 0;
	mprop->zoom = 15;
	mprop->zmod = 2;
	mprop->strtx = MAP_WID / 4;
	mprop->strty = MAP_LEN / 4;
	mprop->perspective = 0;
	mprop->mlx_ptr = mlx_init();
	mprop->win_ptr = mlx_new_window(mprop->mlx_ptr, MAP_WID, MAP_LEN, "FdF");
}

static void	init_eye(t_mprop *mprop)
{
	if (!(mprop->eye = (t_eye *)malloc(sizeof(t_eye))))
		put_err(2);
	mprop->eye->ex = -500;
	mprop->eye->ey = -500;
	mprop->eye->ez = 4000;
}

void		init_map(t_mprop *mprop)
{
	init_mprop(mprop);
	init_eye(mprop);
}
