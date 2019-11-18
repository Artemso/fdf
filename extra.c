/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:19:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 17:16:57 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
