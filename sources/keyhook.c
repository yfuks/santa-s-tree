/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:51:17 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 14:55:06 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santa.h"

int		keyhook(char buffer[3])
{
/*	if (buffer[0] == KEY_ARROW && buffer[1] == '[' && buffer[2] == 'C')
		write(1, "right", 5);
	else if (buffer[0] == KEY_ARROW && buffer[1] == '[' && buffer[2] == 'D')
		write(1, "left", 4);
	else if (buffer[0] == KEY_ARROW && buffer[1] == '[' && buffer[2] == 'A')
		write(1, "Up", 2);
	else if (buffer[0] == KEY_ARROW && buffer[1] == '[' && buffer[2] == 'B')
		write(1, "Down", 4);
	else if (buffer[0] == KEY_NEWLINE && !buffer[1] && !buffer[2])
		write(1, "Entrer", 6);
	else if (buffer[0] == KEY_SPACE && !buffer[1] && !buffer[2])
		write(1, "Espace", 6);
		else*/ if (buffer[0] == KEY_ESC)
		return (1);
	ft_memset(buffer, 0, 3);
	return (0);
}
