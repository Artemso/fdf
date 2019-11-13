/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:45:26 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/13 16:44:36 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
#define FdF_H

# include "./libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define SPACE ' '

/*
** Macros for line drawing algorithm
*/

# define begx beg->x
# define endx end->x
# define begy beg->y
# define endy end->y

/*
** Macros for t_mprop modification
*/

# define pmap mprop->map
# define pmapcnt mprop->map[cnt]
# define pmap_x mprop->map[cnt]->x
# define pmap_y mprop->map[cnt]->y
# define pmap_z mprop->map[cnt]->z

/*
** MLX and WIN pointers
*/

# define pmlx mprop->mlx_ptr;
# define pwin mprop->win_ptr;
# define ln_cnt mprop->nlines;

typedef struct		s_pmap
{
	int				x;
	int				y;
	int				z;

	int				colour;
	int				ix;
	int				iy;
}					t_pmap;

typedef struct		s_mprop
{
	t_pmap			**map;

	int				width;
	int				nlines;

	int				ptcnt;

	double			zoom;
	double			zmod;
	int				strtx;
	int				strty;

	void			*mlx_ptr;
	void			*win_ptr;
}					t_mprop;


void	draw_line(void *mlx_ptr, void *win_ptr, t_pmap *beg, t_pmap *end);
void	get_input(char **argv, t_mprop *mprop);
int		key_hook(int keycode, t_mprop *mprop);
int		expose_hook(t_mprop *mprop);
void		clean_map(t_mprop *mprop);

#endif