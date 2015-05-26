/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:35:33 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 15:26:52 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "santa.h"

int		main(void)
{
	t_env 	e;

	ft_memset(e.buffer, 0, 3);
	if (get_term(&e))
	{
		ft_putstr(CLEAR_TERM);
		set_term_cano(&e);
		while (42)
		{
			get_size(&e);
			draw_tree(&e);
			usleep(60000);
			if (keyhook(e.buffer))
				break;
		}
		reset_term(&e);
		ft_putstr(REPUT_TERM);
	}
	return (0);
}
