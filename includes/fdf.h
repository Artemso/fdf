/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:45:26 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/15 17:42:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FdF_H
#define FdF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "color.h"

# define SPACE ' '
# define MAP_WID 1920
# define MAP_LEN 1080

/*
** Macros for line drawing algorithm
*/

# define begx beg->ix
# define endx end->ix
# define begy beg->iy
# define endy end->iy

/*
** Macros for t_mprop modification
*/

# define pmap mprop->map[cy][cx]
# define pmap_x mprop->map[cy][cx]->x
# define pmap_y mprop->map[cy][cx]->y
# define pmap_z mprop->map[cy][cx]->z

/*
** MLX and WIN pointers
*/

# define pmlx mprop->mlx_ptr
# define pwin mprop->win_ptr
# define ln_cnt mprop->nlines

typedef struct		s_eye
{
	int				ex;
	int				ey;
	int				ez;
}					t_eye;

typedef	struct		s_pcur
{
	int				x;
	int				y;
}					t_pcur;

typedef struct		s_pmap
{
	int				x;
	int				y;
	int				z;

	int				color;
	int				ix;
	int				iy;
}					t_pmap;

typedef struct		s_mprop
{
	t_pmap			***map;
	t_eye			*eye;

	int				width;
	int				nlines;

	int				ptcnt;
	int				perspective;

	double			zoom;
	double			zmod;
	int				strtx;
	int				strty;

	void			*mlx_ptr;
	void			*win_ptr;

	int				dx;
	int				dy;
	int				stpx;
	int				stpy;
	int				zmin;
	int				zmax;
}					t_mprop;

void	draw_line(t_mprop *mprop, t_pmap *beg, t_pmap *end);
void	get_input(char **argv, t_mprop *mprop);
int		key_hook(int keycode, t_mprop *mprop);
int		expose_hook(t_mprop *mprop);
void	clean_map(t_mprop *mprop);
int 	set_color(t_mprop *mprop, t_pmap *curr);
int		get_color(t_mprop *mprop, t_pmap *beg, t_pmap *end, t_pcur *pcur);
void	get_iso(t_mprop *mprop);
void	get_conic(t_mprop *mprop);
void	get_perspective(t_mprop *mprop, t_eye *eye);

#endif