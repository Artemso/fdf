/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:25:08 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/14 16:31:49 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int keycode, t_mprop *mprop)
{
	if (keycode == 69)
	{
		mprop->zoom += 1;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	else if (keycode == 78 && mprop->zoom > 1)
	{
		mprop->zoom -= 1;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
}

static void	zmod(int keycode, t_mprop *mprop)
{
	if (keycode == 6)
	{
		mprop->zmod += 0.1;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 7)
	{
		mprop->zmod -= 0.1;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
}

static void	move(int keycode, t_mprop *mprop)
{
	if (keycode == 126)
	{
		mprop->strty -= 5;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 125)
	{
		mprop->strty += 5;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 123)
	{
		mprop->strtx -= 5;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 124)
	{
		mprop->strtx += 5;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
}

int			key_hook(int keycode, t_mprop *mprop)
{
	if (keycode == 53)
		exit(1);
	zoom(keycode, mprop);
	move(keycode, mprop);
	zmod(keycode, mprop);
	return (0);
	// if (keycode == 18 || keycode == 83)
	// 	key 1 (conic persp)
	// if (keycode == 19 || keycode == 84)
	// 	key 2 (iso persp)
}

