/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:33:48 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 19:21:55 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		count_width(t_mprop *mprop, char **newline, int cnt)
{
	mprop->width = 0;
	while (newline[mprop->width] != NULL)
	{
		if (cnt == 0)
			mprop->initwidth++;
		mprop->width++;
	}
	if (mprop->initwidth != mprop->width)
		put_err(0);
	return (mprop->width);
}

static void		count_lines(char *argv, t_mprop *mprop)
{
	int		fd;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		put_err(0);
	while (get_next_line(fd, &line) > 0)
	{
		mprop->nlines++;
		ft_strdel(&line);
	}
	if (mprop->nlines == 0)
		put_err(0);
	close(fd);
}

static void		store_line(t_mprop *mprop, char *line, int cy)
{
	char	**newline;
	int		arrlen;
	int		cx;

	cx = 0;
	newline = ft_strsplit(line, SPACE);
	arrlen = count_width(mprop, newline, cy);
	if (!(mprop->map[cy] = (t_pmap **)malloc((arrlen + 1) * sizeof(t_pmap *))))
		put_err(2);
	while (newline[cx] != NULL)
	{
		if (!(mprop->map[cy][cx] = (t_pmap *)malloc(sizeof(t_pmap))))
			put_err(2);
		mprop->map[cy][cx]->y = cy;
		mprop->map[cy][cx]->x = cx;
		mprop->map[cy][cx]->z = ft_atoi(newline[cx]);
		ft_strdel(&newline[cx]);
		cx++;
	}
	mprop->map[cy][cx] = NULL;
	free(newline);
}

static void		get_maxminz(t_mprop *mprop)
{
	int	cx;
	int	cy;

	cy = 0;
	cx = 0;
	mprop->zmin = mprop->map[cy][cx]->z;
	mprop->zmax = mprop->map[cy][cx]->z;
	while (cy < mprop->nlines)
	{
		cx = 0;
		while (cx < mprop->width)
		{
			if (mprop->map[cy][cx]->z > mprop->zmax)
				mprop->zmax = mprop->map[cy][cx]->z;
			else if ((mprop->map[cy][cx]->z < mprop->zmin))
				mprop->zmin = mprop->map[cy][cx]->z;
			cx++;
		}
		cy++;
	}
}

void			get_input(char **argv, t_mprop *mprop)
{
	int		fd;
	char	*line;
	int		cnt;

	cnt = 0;
	count_lines(argv[1], mprop);
	if (!(mprop->map = (t_pmap ***)malloc((mprop->nlines + 1)
				* sizeof(t_pmap **))))
		put_err(2);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		put_err(0);
	while (get_next_line(fd, &line) > 0)
	{
		validate_str(line);
		store_line(mprop, line, cnt);
		ft_strdel(&line);
		cnt++;
	}
	mprop->map[cnt] = NULL;
	get_maxminz(mprop);
	close(fd);
}
