/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:17 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/18 17:18:26 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	validate_str(t_mprop *mprop, char *line, int cnt)
{
	int	x;

	x = 0;
	if (line != 0)
	{
		while (line[x] != '\0')
		{
			if (!(ft_isdigit(line[x]) == 1 || line[x] == ' ' || line[x] == '-'))
				put_err(0);
			x++;
		}
	}
	else
		put_err(0);
}
