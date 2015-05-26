/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:56:13 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 14:56:38 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santa.h"

int		get_size(t_env *e)
{
	if ((ioctl(0, TIOCGWINSZ, &e->win_size)) != -1)
	{
		e->height = e->win_size.ws_row;
		e->width = e->win_size.ws_col;
	}
	else if (tgetnum("li") != ERR && tgetnum("co") != ERR)
	{
		e->height = tgetnum("li");
		e->width = tgetnum("co");
	}
	else
		return (0);
	return (1);
}
