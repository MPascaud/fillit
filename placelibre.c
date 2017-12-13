/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placelibre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:30:31 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/13 14:59:59 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int			placelibre(t_list *maillon, char *carre)
{
	int		i;
	int		cote;

	i = 0;
	cote = 0;
	while (carre[i] != '\n')
		i++;
	cote = i;
	i = 0;
	while (i < 4)
	{
		if (carre[maillon->position + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] == '\n'
				|| carre[maillon->position + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] == '\0'
				|| carre[maillon->position + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] == '#')
			return (0);
		i++;
	}
	return (1);
}*/



int		placelibre(t_list *maillon, char *carre)
{
	int		i;
	int		ok;
	int		cote;
	int		tmp;

	cote = 0;
	tmp = maillon->position;
	while (carre[cote] != '\n')
		cote++;
	while (tmp < ((cote + 1) * cote) - 4)
	{
		ok = 0;
		i = 0;
		while (carre[tmp + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] == '.')
		{
			i++;
			ok++;
			if (ok == 4)
			{
/*				printf("position = %d\n", tmp);
				printf("cote = %d\n", cote);
				printf("i = %d\n", i);
				printf("%s\n", "x[i] = ");
				printf("%d\n", maillon->x[i]);
				printf("%s\n", "y[i] = ");
				printf("%d\n", maillon->y[i]);*/
				return (tmp);
			}
		}
		tmp++;
	}
	return (-1);
}
