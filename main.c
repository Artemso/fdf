/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:17:53 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/12 15:24:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		store_line(t_pmap **map, char *line, int ln_cnt, int *ar_cnt)
{
	char		**newline;
	int			cnt;

	cnt = 0;
	newline = ft_strsplit(line, SPACE);
	while (newline[cnt] != NULL)
	{
		map[(*ar_cnt)] = (t_pmap *)malloc(sizeof(t_pmap));
		map[(*ar_cnt)]->value = ft_atoi(newline[cnt]);
		map[(*ar_cnt)]->x = cnt * MAP_SCALE;
		map[(*ar_cnt)]->y = ln_cnt * MAP_SCALE;
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

int			main(int argc, char **argv)
{
	t_pmap		**map;
	char		*line;
	int			ln_cnt;
	int			fd;
	int			ar_cnt;
	int			chr_cnt;
	void		*mlx_ptr;
	void		*win_ptr;
	int			z;

	z = 0;
	ar_cnt = 0;
	chr_cnt = 0;
	if (argc == 2)
	{
		count_points(argv[1], &chr_cnt);
		map = (t_pmap **)malloc(chr_cnt * sizeof(t_pmap *));
		ln_cnt = 0;
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			store_line(map, line, ln_cnt, &ar_cnt);
			ln_cnt++;
		}
		map[ar_cnt] = 0;
		ft_strdel(&line);
		close(fd);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, chr_cnt * 5, chr_cnt * 5, "Artem's window");
		while (map[z] != 0)
		{
			if (map[z]->value > 0)
				mlx_pixel_put(mlx_ptr, win_ptr, map[z]->x, map[z]->y, 16737535);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, map[z]->x, map[z]->y, 16777215);
			z++;
		}
		draw_line(mlx_ptr, win_ptr, map[2], map[4]);
		mlx_loop(mlx_ptr);
	}
	return (0);
}
