/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 20:25:51 by yfuks             #+#    #+#             */
/*   Updated: 2014/12/08 16:59:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list		*cursor;

	cursor = *alst;
	if (*alst && new)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
}
