/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agencement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:55:27 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/13 19:10:35 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

/*char	*agencement(t_list **liste, char *carre)
{
	t_list *maillon;

	maillon = *liste;
	if (maillon->previous == NULL)
	{
		if (maillon->position = 1)
			return (NULL);
		maillon->position = 1;
		maillon = maillon->next;
	}
	while (maillon != NULL)
	{
		if (maillon->previous == NULL)
			return (NULL);
		if (!placement(maillon, carre) && maillon->next)
		{
			maillon->position = 0;
			maillon = maillon->previous;
			maillon->position = maillon->position + 1;
			agencement(&maillon, carre);
		}
		maillon = maillon->next;
	}
	return (carre);
}*/


void	backdot(t_list *maillon, char *carre)
{
	int		cote;
	int		i;

	cote = 0;
	i = 0;
	while (carre[cote] != '\n')
		cote++;
	while (i < 4)
	{
		carre[maillon->position + maillon->x[i] + ((maillon->y[i]) * (cote + 1))] = '.';
		i++;
	}
}


char	*agencement(t_list *liste, char *carre)
{

//	printf("%s\n", "coucou");
	while (liste->previous != NULL)
	{
		printf("%d\n", liste->position);
	//	printf("%s\n", "coucou");
		if (placelibre(liste, carre) == -1)
		{
			printf("liste->position = %d\n", liste->position);
			liste->position = 0;
			if (liste->previous == NULL)
				return (NULL);
		//	printf("%s\n", "coucou444");
			liste = liste->previous;
			if (liste->previous == NULL)
				return (NULL);
			backdot(liste, carre);
			liste->position++;
			if (liste->previous == NULL)
			{
				printf("%s\n", "coucou5");
				return (NULL);
			}
		}
		if (placelibre(liste, carre) >= 0)
		{
			liste->position = placelibre(liste, carre);
			placement(liste, carre);
			if (liste->next == NULL)
				return (carre);
			if (liste->previous == NULL)
				return(NULL);
			liste = liste->next;
		}
	}
	return (NULL);
}



//placebarre
//next
//place carre
//next
//
//





