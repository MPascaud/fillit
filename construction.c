/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reso.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:05:29 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/14 11:56:23 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

t_list	*ft_lstnew(int *x, int *y, int position, t_list *maillon, char c)
{
	t_list	*maillonenplus;

	if(!(maillonenplus = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ft_memcpy(maillonenplus->x, x, ((sizeof(int)) * 4));//copie de x dans blabla->x
	ft_memcpy(maillonenplus->y, y, ((sizeof(int)) * 4));//idem pour y
	maillonenplus->position = position;//position dans nouveau maillon
	maillonenplus->lettre = c;
	maillonenplus->previous = maillon;//le maillon est le previous du nouveau
	maillonenplus->next = NULL;//ajout dans liste chainee : next == NULL
	return (maillonenplus);
}
//rajouter lettres et afficher en cours, avec placement aussi pour la lettre
void	decalageverslagauche(int *x, int *y)
{
	int		i;
	int		petitx;
	int		petity;

	i = 0;
	petitx = x[0];
	petity = y[0];
	while (i < 4)
	{
		if (petitx > x[i])
		{
			petitx = x[i];
		}
		if (petity > y[i])
		{
			petity = y[i];
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		x[i] = x[i] - petitx;
		y[i] = y[i] - petity;
		i++;
	}
}


t_list	*construction(char *enter)
{
	int		i;
	int		j;
	int		carriages;
	int		lines;
	t_list	*maillon;
	t_list	*debut;
	int		x[4] = {0,0,0,0};
	int		y[4] = {0,0,0,0};
	char	c;

	i = 0;
	j = 0;
	carriages = 0;
	lines = 0;
	c = 'A';
	maillon = ft_lstnew(x, y, 0, NULL, '0');//x[i] et y[i] = 0, position 0, previous NULL
	debut = maillon;
	while (enter[i] != '\0')
	{
		if (enter[i] == '#')
		{
			x[j] = (i - carriages) % 5;
			y[j] = lines % 4;
			j++;
		}
		if ((enter[i] == '\n' && enter[i + 1] == '\n') || enter[i + 1] == '\0')
		{
			decalageverslagauche(x, y);//coordonnees rectifiees
			carriages++;
			j = 0;
			maillon->next = ft_lstnew(x, y, 0, maillon, c);
			c++;
			maillon = maillon->next;
		}
		if (enter[i] == '\n' && enter[i - 1] != '\n')
				lines++;
		i++;
	}
	return (debut);
}
