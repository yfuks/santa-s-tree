/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 11:17:13 by yfuks             #+#    #+#             */
/*   Updated: 2014/12/09 11:46:11 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			lstsize(t_list **head)
{
	t_list		*cursor;
	int			count;

	count = 0;
	cursor = *head;
	while (cursor)
	{
		cursor = cursor->next;
		count++;
	}
	return (count);
}
