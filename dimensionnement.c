/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agrandissement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:10:27 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/14 21:30:46 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char	*dimensionnement(int tetris, t_list *liste)
{
	char	*carre;
//	int		tetris;
//	t_list	*plaf;
	t_list	*tkt;
	int		cote;

	tkt = liste;
	cote = 0;
//	printf("tetris : %d\n", tetris);
//	agencement(liste, carre);
	carre = dimensions(tetris);
	while (carre[cote] != '\n')
		cote++;
//	printf("cote = %d\n", cote);
	while (agencement(liste, carre) == NULL)
	{
		cote++;
		carre = constructioncarre(cote);
	}
//	printf("cote = %d\n", cote);
//	printf("carre : %s\n", carre);
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







