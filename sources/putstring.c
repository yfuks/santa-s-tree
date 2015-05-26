/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:12:49 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 15:14:09 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santa.h"

static int	output(int c)
{
	ft_putchar(c);
	return (0);
}

void		put_cursor(int x, int y)
{
	char	*cursor;

	cursor = tgetstr("cm", NULL);
	tputs(tgoto(cursor, x, y), 1, output);
}

void	put_string(char *str, int x, int y)
{
	char	*cursor;

	put_cursor(x, y);
	ft_putstr(str);
	cursor = tgetstr("me", NULL);
	tputs(cursor, 1, output);
}
