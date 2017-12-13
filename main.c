/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:57:31 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/13 19:30:32 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



int			main(int argc, char **argv)
{
	int		fd;
	char	tmp[1024];
	int		i;
	int		tetris;
	t_list	*liste;
	char	*carre;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <input_file>\0");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	read(fd, tmp, 545);

	printf ("\n----------------------\nVALIDITE : %d\n", validite(tmp));

//	printf("--------------------\nCARRE DE DEPART\n%s", carredepart(tmp));

//	printf("\n%s\n","-----------------------------------\nCONSTRUCTION DE LISTE CHAINEE");
	liste = (construction(tmp));
//	afficherliste(&liste);
	printf("%s\n", "----------------------------------");

	t_list	*maillon;
	int		x[4] = {0,0,0,0};
	int		y[4] = {0,1,2,3};
	maillon = ft_lstnew(x, y, 0, NULL);

//	char	carre[50] = "....\n....\n....\n....\0";
//	carre = carredepart(tmp);
//	printf("PLACEMENT POSSIBLE : %d\n", placement(maillon, carre));
//	placement(maillon, carre);
//	printf("Place libre : %d\n", placelibre(maillon, carre));
//	printf("%s\n", carre);
//	printf("place libre : %d\n", placelibre(liste, carre));
//	placement (liste, carre);
	liste = liste->next;
//	printf("%s\n", agencement(liste, carre));
//	printf("%s\n", carre);
//	afficherliste(&liste);
	tetris = nombretetris(tmp);
	carre = dimensions(14);
	printf("carredepart : \n%s\n", carre);
	printf("%s\n", agencement(liste, carre));
//	printf("%s\n", dimensionnement(tetris, liste));
	return (0);
}

//si placement == 0 maillon = maillon->previous
//&& on remet les '#' du carre a '.' && maillon->position++; (fonction pour ca(agencement))
//&& on refait le placement
//
//si tout est faux tout le long (maillon->previous ==  NULL) : on recommence tout avec un carre plus grand
//
//
//
//si placelibre, placement, next
//si placement impossible, position=0, previous, position++, on refait
