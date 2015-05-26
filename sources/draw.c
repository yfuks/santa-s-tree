/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:58:00 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 15:25:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santa.h"

void	draw_tree(t_env *e)
{
	int		espaces;
	int		r;
	int 	line;
	int		x;
	int		y;
	int		HauteurSapin = e->height - 10;

	x = 0;
	y = 0;
	line = 0;
	while (line < 4)
	{
		x = 0;
		while (x < e->width)
		{
			put_string(" ", x, y);
			x++;
		}
		line++;
	}
	line = 0;
	while (line < e->height - (e->height / 10))
	{
		x = 0;
		espaces = (HauteurSapin * 3) / 2;
		while (espaces > (line * 2 + 1 - 4 * (line / 4)) / 2)
		{
			put_string(" ", x, line);
			x++;
			espaces--;
		}
		r = 0;
		while (r < (line * 2 + 1 - 4 * (line / 4)))
		{
			if (line > HauteurSapin / 40)
			{
				if (rand()%30 == 1)
				{
					if (rand()%2 == 1)
						put_string("\033[34mO", x, line);
					else if (rand()%2 == 1)
						put_string("\033[31mO", x, line);
					else
						put_string("\033[36mO", x, line);
				}
				else
					put_string("\033[32m#", x, line);
			}
			else
				put_string("\033[33m*", x, line);
			r++;
			x++;
		}
		while (x < (HauteurSapin * 3))
		{
			put_string(" ", x, line);
			x++;
		}
		y++;
		line++;
	}
}
