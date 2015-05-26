/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfloat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:15:44 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/03 19:00:26 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putfloat(float nbr, unsigned int p)
{
	long	l;
	float	r;

	if (nbr < 0)
		write(1, "-", 1);
	l = (long)nbr;
	r = 0.5;
	if ((ft_fabs(nbr - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	ft_putlong(l);
	nbr = ft_fabs(nbr - l);
	if (nbr > 0 && p != 0)
	{
		write(1, ".", 1);
		while (p--)
		{
			nbr = nbr * 10;
			l = (long)nbr;
			l = l % 10;
			nbr = nbr - l;
			ft_putchar(l + 48);
		}
	}
}
