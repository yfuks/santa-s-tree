/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:44:29 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 14:49:19 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santa.h"

int		get_term(t_env *e)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (0);
	if (tgetent(NULL, name_term) == ERR)
		return (0);
	if (tcgetattr(0, &e->term) == -1)
		return (0);
	return (1);
}

int		set_term_cano(t_env *e)
{
	e->term.c_lflag &= ~(ICANON);
	e->term.c_lflag &= ~(ECHO);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(e->term)) == -1)
		return (0);
	return (1);
}

int		reset_term(t_env *e)
{
	if (tcgetattr(0, &e->term) == -1)
		return (0);
	e->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &e->term) == -1)
		return (0);
	return (1);
}
