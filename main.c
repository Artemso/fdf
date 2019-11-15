/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:17:53 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/15 17:45:00 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int			expose_hook(t_mprop *mprop)
{
	if (mprop->perspective == 0)
		get_conic(mprop);
	else if (mprop->perspective == 1)
		get_iso(mprop);
	else if (mprop->perspective == 2)
		get_perspective(mprop, mprop->eye);
	return (1);
}

static void	init_mprop(char **argv, t_mprop *mprop)
{
	mprop->ptcnt = 0;
	mprop->nlines = 0;
	mprop->width = 0;
	mprop->zoom = 30;
	mprop->zmod = 30;
	mprop->strtx = 800;
	mprop->strty = 700;
	mprop->perspective = 0;
	mprop->mlx_ptr = mlx_init();
	mprop->win_ptr = mlx_new_window(mprop->mlx_ptr, MAP_WID, MAP_LEN, "FdF");
	get_input(argv, mprop);
}

static void	init_eye(t_mprop *mprop)
{
	mprop->eye = malloc(sizeof(t_eye));
	mprop->eye->ex = 320;
	mprop->eye->ey = 240;
	mprop->eye->ez = 1200;
}

int			main(int argc, char **argv)
{
	t_mprop *mprop;

	if (argc == 2)
	{
		mprop = (t_mprop *)malloc(sizeof(t_mprop));
		init_mprop(argv, mprop);
		init_eye(mprop);
		mlx_expose_hook(mprop->win_ptr, &expose_hook, mprop);
		mlx_key_hook(mprop->win_ptr, key_hook, mprop);
		mlx_hook(mprop->win_ptr, 2, 0, key_hook, mprop);
		mlx_loop(mprop->mlx_ptr);
	}
	return (0);
}
