/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:41:44 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/13 11:21:06 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(void *param)
{
	printf("d");
}

int	key_hook(int keycode, void *param)
{
	char *str;
	int x;

	str = ft_itoa(keycode);
	x = ft_strlen(str);
	param = 0;
	write(1, str, x);
	ft_putchar('\n');
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		up!
	if (keycode == 125)
		down!
	if (keycode == 123)
		left!
	if (keycode == 124)
		right!
	if (keycode == 18 || keycode == 83)
		key 1 (conic persp)
	if (keycode == 19 || keycode == 84)
		key 2 (iso persp)
	if (keycode == 69)
		key + numpad zoom
	if (keycode == 78)
		key - numpad zoom 
}

int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int 	*x;

	x = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "FdF");
	mlx_expose_hook(win_ptr, &expose_hook, x);
	mlx_key_hook(win_ptr, &key_hook, x);
	mlx_loop(mlx_ptr);
	return (0);
}
