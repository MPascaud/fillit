/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:30:48 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/14 12:12:28 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int		placement(t_list *maillon, char *carre)
{
	int		i;
	int		j;
	int		cote;

	i = 0;
	j = 0;
	cote = 0;
	while (carre[i] != '\n')
		i++;
	cote = i;
	i = 0;
	if (placelibre(maillon, carre) == 1)
	{
		while (i < 4)
		{
			carre[maillon->position + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] = '#';
			i++;
		}
	}
	else
	{
		if (maillon->position >= (cote + 1) * (cote - 1))
		{
			return (0);
		}
		maillon->position = maillon->position + 1;
		placement (maillon, carre);
	}
	if (maillon->position >= (cote + 1) * (cote - 1))
	{
		return (0);
	}
	return (1);
}*/

void		placement(t_list *maillon, char *carre)
{
	int		i;
	int		cote;
	char	c;

	c = maillon->lettre;
	i = 0;
	cote = 0;
	while (carre[cote] != '\n')
		cote++;
	while (i < 4)
	{
		carre[maillon->position + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] = c;
		i++;
	}
}

