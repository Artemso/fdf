/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:19:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 18:08:22 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		key_hook_release(int keycode, t_mprop *mprop)
{
	if (keycode == 21 && mprop->palette == 0)
		mprop->palette = 1;
	else if (keycode == 21 && mprop->palette == 1)
		mprop->palette = 0;
	mlx_clear_window(mprop->mlx_ptr, mprop->win_ptr);
	expose_hook(mprop);
	return (0);
}

void	display_legend(t_mprop *mprop)
{
	mlx_string_put(PMLX, PWIN, 5,
				5, WHITE, "Use direction keys to move the map");
	mlx_string_put(PMLX, PWIN, 5, 30, WHITE, "Z and X to modify the Z value");
	mlx_string_put(PMLX, PWIN, 5, 55, WHITE, "+ and - to zoom in and out");
	mlx_string_put(PMLX, PWIN, 5,
				80, WHITE, "1: isometric, 2: conic, 3: perspective");
	mlx_string_put(PMLX, PWIN, 5,
				105, WHITE, "WASD: eye position (perspective mode)");
	mlx_string_put(PMLX, PWIN, 5,
				130, WHITE, "4: change colour palette");
}

void	validate_str(t_mprop *mprop, char *line, int cnt)
{
	int	x;

	x = 0;
	if (line != 0)
	{
		while (!(line[x] == '\0' || line[x] == ','))
		{
			if (!(ft_isdigit(line[x]) == 1 || line[x] == ' ' || line[x] == '-'))
				put_err(0);
			x++;
		}
	}
	else
		put_err(0);
}

void	put_err(int x)
{
	if (x == 0)
	{
		ft_putstr("invalid map file\n");
		exit(0);
	}
	if (x == 1)
	{
		ft_putstr("usage: ./fdf map_file.fdf\n\n");
		ft_putstr("Properties of a valid map:\n");
		ft_putstr("A rectangular grid, containing numbers ");
		ft_putstr("separated by spaces.");
		exit(0);
	}
	if (x == 2)
	{
		ft_putstr("memory error\n");
		exit(0);
	}
}
