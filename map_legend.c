/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_legend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:19:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 11:05:36 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	display_legend(t_mprop *mprop)
{
	mlx_string_put(pmlx, pwin, 5, 5, WHITE, "Direction keys to move the map");
	mlx_string_put(pmlx, pwin, 5, 30, WHITE, "Z and X to modify the Z value");
	mlx_string_put(pmlx, pwin, 5, 55, WHITE, "+ and - to zoom in and out");
	mlx_string_put(pmlx, pwin, 5, 80, WHITE, "1: iso, 2: conic, 3: parallel");
	mlx_string_put(pmlx, pwin, 5, 105, WHITE, "WASD- The eye position");
}
