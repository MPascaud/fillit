/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taillecarre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:49:40 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/12 19:57:39 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*constructioncarre(int cote)
{
	int		lines;
	int		i;
	char	*blop;

	lines = 0;
	i = 0;
	if(!(blop = (char*)malloc(sizeof(char) * ((cote * cote) + cote + 1))))
		return (NULL);
	blop[i] = '.';
	i++;
	while (lines < cote)
	{
		while (i % (cote + 1) < cote)
		{
			blop[i] = '.';
			i++;
		}
		blop[i] = '\n';
		i++;
		lines++;
	}
	blop[(cote * cote) + cote - 1] = '\0';
	return (blop);
}

char		*dimensions(int tetriminos)
{
	int		blocks;
	int		c;

	c = 0;
	blocks = tetriminos * 4;
	while (c * c < blocks)
	{
		c++;
	}
	return (constructioncarre(c));
}

int			nombretetris(char *tmp)
{
	int		i;
	int		tetris;

	i = 0;
	tetris = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n' && (tmp[i + 1] == '\n' || tmp[i + 1] == '\0'))
			tetris++;
		i++;
	}
	return (tetris);
}

char		*carredepart(char *tmp)
{
	int		i;
	int		tetris;

	i = 0;
	tetris = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n' && (tmp[i + 1] == '\n' || tmp[i + 1] == '\0'))
			tetris++;
		i++;
	}
	return (dimensions(tetris));
}








