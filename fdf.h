/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:45:26 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/12 14:44:49 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
#define FdF_H

# include "./libft/libft.h"
# include "mlx.h"
# include <math.h>

# define SPACE ' '
# define ZOOM 25
# define MAP_SCALE 25

# define begx beg->x
# define endx end->x
# define begy beg->y
# define endy end->y

typedef struct		s_pmap
{
	int				value;
	int				colour;
	int				x;
	int				y;
}					t_pmap;

typedef struct		s_map
{
	int				x;
	int				y;
}					t_map;


void	draw_line(void *mlx_ptr, void *win_ptr, t_pmap *beg, t_pmap *end);

#endif