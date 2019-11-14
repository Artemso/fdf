/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:17:53 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/14 15:30:31 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		clean_map(t_mprop *mprop)
{
	int x;
	int y;

	x = 0;
	while (x <= MAP_WID)
	{
		y = 0;
		while (y <= MAP_LEN)
		{
			mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, x, y, 0);
			y++;
		}
		x++;
	}
}

static void	draw_iso(t_mprop *mprop)
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

static void	get_iso(t_mprop *mprop)
{
	int	cx;
	int	cy;
	cy = 0;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			pmap->ix =(mprop->strtx + (pmap_x - pmap_y) * cos(0.523599)) * mprop->zoom;
			pmap->iy =(mprop->strty + (-pmap_z * mprop->zmod) + (pmap_x  + pmap_y) * sin(0.523599)) * mprop->zoom;
			cx++;
		}
		cy++;
	}
	draw_iso(mprop);
}

int			expose_hook(t_mprop *mprop)
{
	get_iso(mprop);
	return (1);
}

static void	init_mprop(char **argv, t_mprop *mprop)
{
	mprop->ptcnt = 0;
	mprop->nlines = 0;
	mprop->width = 0;
	mprop->zoom = 20;
	mprop->zmod = 1.5;
	mprop->strtx = 20;
	mprop->strty = 15;
	mprop->mlx_ptr = mlx_init();
	mprop->win_ptr = mlx_new_window(mprop->mlx_ptr, MAP_WID, MAP_LEN, "FdF");
	get_input(argv, mprop);
}

int			main(int argc, char **argv)
{
	t_mprop *mprop;

	if (argc == 2)
	{
		mprop = (t_mprop *)malloc(sizeof(t_mprop));
		init_mprop(argv, mprop);
		mlx_expose_hook(mprop->win_ptr, &expose_hook, mprop);
		mlx_key_hook(mprop->win_ptr, &key_hook, mprop);
		mlx_loop(mprop->mlx_ptr);
	}
	return (0);
}
