/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:17:53 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/13 14:54:38 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		clean_map(t_mprop *mprop)
{
	int x;
	int y;
	
	x = 0;
	while (x <= 640)
	{
		y = 0;
		while (y <= 480)
		{
			mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, x, y, 0);
			y++;
		}
		x++;
	}
}

static void	get_iso(t_mprop *mprop)
{
	int cnt;

	cnt = 0;
	while (cnt < mprop->ptcnt)
	{
		pmapcnt->ix = mprop->strtx - (mprop->zoom * pmap_y) + (mprop->zoom * pmap_x);
		pmapcnt->iy = mprop->strty + ((mprop->zoom) * pmap_x) + ((mprop->zoom) * pmap_y) - (pmap_z * mprop->zmod);
		cnt++;
	}
	cnt = 0;
	while (cnt < mprop->ptcnt)
	{
		mlx_pixel_put(mprop->mlx_ptr, mprop->win_ptr, pmapcnt->ix, pmapcnt->iy, 16737535);
		cnt++;
	}
}

int			expose_hook(t_mprop *mprop)
{
	get_iso(mprop);
	return (1);
}

static void	init_mprop(char **argv, t_mprop *mprop)
{
	mprop->ptcnt = 0;
	mprop->zoom = 1.1;
	mprop->zmod = 1.1;
	mprop->strtx = 200;
	mprop->strty = 100;
	mprop->mlx_ptr = mlx_init();
	mprop->win_ptr = mlx_new_window(mprop->mlx_ptr, 640, 480, "FdF");
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
