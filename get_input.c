/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:33:48 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/13 16:46:56 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		store_line(t_pmap **map, char *line, t_mprop *mprop, int *ar_cnt)
{
	char		**newline;
	int			cnt;

	cnt = 0;
	newline = ft_strsplit(line, SPACE);
	while (newline[cnt] != NULL)
	{
		map[(*ar_cnt)] = (t_pmap *)malloc(sizeof(t_pmap));
		map[(*ar_cnt)]->z = ft_atoi(newline[cnt]);
		map[(*ar_cnt)]->x = cnt;
		map[(*ar_cnt)]->y = ln_cnt;
		cnt++;
		(*ar_cnt)++;
	}
}

static void		count_points(char *argv, int *str_cnt)
{
	int		fd;
	int		cnt;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		cnt = 0;
		if (line[cnt] != SPACE && line[cnt] != '\0')
			(*str_cnt)++;
		while (line[cnt] != '\0')
		{
			if ((line[cnt] != SPACE) && (line[cnt - 1] == SPACE))
				(*str_cnt)++;
			cnt++;
		}
	}
	ft_strdel(&line);
	close(fd);
}

void			get_input(char **argv, t_mprop *mprop)
{
	int			fd;
	int			chr_cnt;
	char		*line;

	chr_cnt = 0;
	count_points(argv[1], &chr_cnt);
	pmap = (t_pmap **)malloc(chr_cnt * sizeof(t_pmap *));
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		store_line(pmap, line, mprop, &(mprop->ptcnt));
		mprop->nlines = mprop->nlines + 1;
	}
	pmap[mprop->ptcnt] = 0;
	ft_strdel(&line);
	close(fd);
}
