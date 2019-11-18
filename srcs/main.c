/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:17:53 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 19:20:07 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			expose_hook(t_mprop *mprop)
{
	display_legend(mprop);
	if (mprop->perspective == 0)
		get_conic(mprop);
	else if (mprop->perspective == 1)
		get_iso(mprop);
	else if (mprop->perspective == 2)
		get_perspective(mprop, mprop->eye);
	return (1);
}

int			main(int argc, char **argv)
{
	t_mprop *mprop;

	if (argc == 2)
	{
		if (!(mprop = (t_mprop *)malloc(sizeof(t_mprop))))
			put_err(2);
		init_map(mprop);
		get_input(argv, mprop);
		mlx_expose_hook(mprop->win_ptr, expose_hook, mprop);
		mlx_key_hook(mprop->win_ptr, key_hook_press, mprop);
		mlx_key_hook(mprop->win_ptr, key_hook_release, mprop);
		mlx_hook(mprop->win_ptr, 2, 0, key_hook_press, mprop);
		mlx_loop(mprop->mlx_ptr);
	}
	else
		put_err(1);
	return (0);
}
