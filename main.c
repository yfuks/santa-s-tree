/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:46:31 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/25 17:03:03 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#define HauteurSapin 40

typedef struct 	s_snow
{
	char	*text;
}				t_snow;

t_snow snow[5 + (HauteurSapin * 2)][HauteurSapin * 3];

static void		draw_tronc(void)
{
	int		line;
	int		i;
	int		espaces;
	int		x;
	int		y;

	line = 0;
	y = (HauteurSapin + 4);
	while (line < HauteurSapin / 5)
	{
		x = 0;
		espaces = HauteurSapin + (HauteurSapin / 2) - (HauteurSapin / 10);
		while (espaces)
		{
			ft_putstr(snow[y][x].text);
			x++;
			espaces--;
		}
		i = 0;
		while (i < HauteurSapin / 4)
		{
			x++;
			ft_putstr("\e[0;30m|");
			i++;
		}
		while (x < HauteurSapin * 3)
		{
			ft_putstr(snow[y][x].text);
			x++;
		}
		ft_putchar('\n');
		line++;
		y++;
	}
	i = 0;
	while (i++ < HauteurSapin * 3)
		ft_putstr("\033[32m=");
}

static void 	draw_sapin(void)
{
	int espaces;
	int r;
	int line;
	int	x;
	int	y;

	x = 0;
	y = 0;
	line = 0;
	while (y < 4)
	{
		x = 0;
		while (x < HauteurSapin * 3)
		{
			ft_putstr(snow[y][x].text);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	while (line < HauteurSapin)
	{
		x = 0;
		espaces = (HauteurSapin * 3) / 2;
		while (espaces > (line * 2 + 1 - 4 * (line / 4)) / 2)
		{
			ft_putstr(snow[y][x].text);
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
						ft_putstr("\033[34mO");
					else if (rand()%2 == 1)
						ft_putstr("\033[31mO");
					else
						ft_putstr("\033[36mO");
				}
				else
					ft_putstr("\033[32m#");
			}
			else
				ft_putstr("\033[33m*");
			r++;
			x++;
		}
		while (x < (HauteurSapin * 3))
		{
			ft_putstr(snow[y][x].text);
			x++;
		}
		ft_putchar('\n');
		y++;
		line++;
	}	
}

static void	fill_snow(void)
{
	int		x;
	int		y;

	y = 4 + (HauteurSapin * 2);
	while (y >= 0)
	{
		x = (HauteurSapin * 3) - 1;
		while (x >= 0)
		{
			if (y < (4 + HauteurSapin * 2) && snow[y][x].text[0] != ' ')
			{
				snow[y + 1][x].text = ft_strdup("\033[037m*");
				snow[y][x].text = ft_strdup(" ");
			}
			x--;
		}
		y--;
	}
	x = 0;
	while (x < HauteurSapin * 3)
	{
		if (rand()%40 == 1)
			snow[0][x].text = ft_strdup("\033[037m*");
		else
			snow[0][x].text = ft_strdup(" ");
		x++;
	}
}

int 			main(void)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < 5 + (HauteurSapin * 2))
	{
		x = 0;
		while (x < HauteurSapin * 3)
		{
			snow[y][x].text = ft_strdup(" ");
			x++;
		}
		y++;
	}
	while (42)
	{
		fill_snow();
		ft_putstr("\E[H\E[2J");
		draw_sapin();
		draw_tronc();
		usleep(80000);
	}
	return 0;
}
