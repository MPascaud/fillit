/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficherliste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:53:33 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/07 17:47:51 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	afficherliste(t_list **liste)
{
	int		i;
	t_list	*blop;

	blop = *liste;
	while (blop != NULL)
	{
		i = 0;
		while (i < 4)
		{
			printf("x = %d\n", blop->x[i]);
			printf("y = %d\n", blop->y[i]);
			i++;
		}
		printf("position = %d\n", blop->position);
		blop = blop->next;
	}
}
