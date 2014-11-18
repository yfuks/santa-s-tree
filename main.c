/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:46:31 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/18 15:49:15 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define HauteurSapin 30

int main(void)
{
	int espaces;
	int r;
	int line;

	line = 0;
	while (line < HauteurSapin)
	{
		espaces = (HauteurSapin * 3) / 2;
		while (espaces > (line * 2 + 1 - 4 * (line / 4)) / 2)
		{
			printf(" ");
			espaces--;
		}
		r = 0;
		while (r < (line * 2 + 1 - 4 * (line / 4))) 
		{
			printf("\033[32m#");
			r++;
		}
		printf("\n");
		line++;
	}
	return 0;
}
