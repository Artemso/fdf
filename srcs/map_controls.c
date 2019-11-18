/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:25:08 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 19:20:06 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	zoom_zmod(int keycode, t_mprop *mprop)
{
	if (keycode == 69)
	{
		mprop->zoom += 0.5;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	else if (keycode == 78 && mprop->zoom > 1)
	{
		mprop->zoom -= 0.5;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 6)
	{
		mprop->zmod += 0.2;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 7)
	{
		mprop->zmod -= 0.2;
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

static void	perspective(int keycode, t_mprop *mprop)
{
	if (keycode == 20 || keycode == 85)
	{
		mprop->perspective = 2;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		reset_mprop(mprop);
		expose_hook(mprop);
	}
	else if (keycode == 18 || keycode == 83)
	{
		mprop->perspective = 1;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		reset_mprop(mprop);
		expose_hook(mprop);
	}
	else if (keycode == 19 || keycode == 84)
	{
		mprop->perspective = 0;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		reset_mprop(mprop);
		expose_hook(mprop);
	}
}

static void	eye_control(int keycode, t_mprop *mprop)
{
	if (keycode == 0)
	{
		mprop->eye->ex -= 50;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 2)
	{
		mprop->eye->ex += 50;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 13)
	{
		mprop->eye->ey -= 50;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
	if (keycode == 1)
	{
		mprop->eye->ey += 50;
		mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
		expose_hook(mprop);
	}
}

int			key_hook_press(int keycode, t_mprop *mprop)
{
	if (keycode == 53)
		exit(1);
	zoom_zmod(keycode, mprop);
	move(keycode, mprop);
	perspective(keycode, mprop);
	eye_control(keycode, mprop);
	return (0);
}
