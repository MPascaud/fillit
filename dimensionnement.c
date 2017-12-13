/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agrandissement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:10:27 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/13 15:53:09 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char	*dimensionnement(int tetris, t_list *liste)
{
	char	*carre;
//	int		tetris;
//	t_list	*plaf;
	t_list	*tkt;

	tkt = liste;
	printf("tetris : %d\n", tetris);
//	agencement(liste, carre);
	while (tetris)
	{
		liste = tkt;
		carre = dimensions(tetris);
		printf("carre : \n%s\n", carre);
		printf("tetris : %d\n", tetris);
	//	printf("%s\n", "blop");
		if (agencement(liste, carre) != NULL)
		{
			printf("%s\n", "coucou6");
			carre = dimensions(tetris);
			return (agencement(tkt, carre));
		}
	//	afficherliste(&liste);
		printf("%d\n", tetris);
		tetris++;
	}
	printf("%s\n", carre);
	return (carre);
}


/*int		main(int argc, char **argv)
{
	int		fd;
	char	tmp[1024];
	int		i;
	t_list	*liste;

	fd = open(argv[1], O_RDONLY);
	read(fd, tmp, 545);
	liste = construction(tmp);
	liste = liste->next;
	return (0);
}*/

//carredepart
//tant que agencement == NULL, on augmente le carre
//quand/si agencement != NULL, return carre
//
//ou bien nombre de tetriminos
//etc







