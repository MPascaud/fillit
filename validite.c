/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:49:34 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/15 20:39:10 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"


int		demitetri(char *str)
{
	int		i;
	int		tetriok;

	i = 0;
	tetriok = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				if (str[i + 5] == '#' || (i > 0 && str[i - 1] == '#') || (i >= 5 && str[i - 5] == '#'))
					tetriok = 1;
			if (str[i + 5] == '#')
				if (str[i + 1] == '#' || (i > 0 && str[i - 1] == '#') || (i >= 5 && str[i - 5] == '#'))
					tetriok = 1;
			if (i > 0 && str[i - 1] == '#')
				if (str[i + 1] == '#' || str[i + 5] == '#' || (i >= 5 && str[i - 5] == '#'))
					tetriok = 1;
			if (i >= 5 && str[i - 5] == '#')
				if (str[i + 1] == '#' || str[i + 5] == '#' || (i > 0 && str[i - 1] == '#'))
					tetriok = 1;
		}
		if (str[i + 1] == '\0' || (str[i + 1] == '\n' && str[i + 2] == '\n'))
		{
			if (tetriok == 0)
				return (0);
			tetriok = 0;
		}
		i++;
	}
	return (1);
}

static int		validite2(int characters, int lines, int hashtags, char *str)
{
	int		i;

//	printf("hashtags = %d\n", hashtags);
//	printf("lines = %d\n", lines);
	i = 0;
	if (str[i] != '#' && str[i] != '.' && str[i] != '\n')//mauvais signes
		return (0);
	if (str[i] == '\n')
	{
		if (str[i + 1] == '\n')//si 2 \n a la suite
		{
			if (str[i + 2] == '\n' || lines != hashtags
					|| characters == 0
					|| characters % 4 != 0)//3 \n a la suite, ou pas bon nombre de #, ou fichier commence par 2 \n, ou pas bon nombre de (# & .)
			{
				return (0);
			}
		}
	}
	if (characters % 4 == 0 && str[i] != '\n')//au niveau de la 4e colonne
	{
		if (str[i + 1] != '\n')//pas de \n en +1
			return (0);
	}
	if (lines % 4 == 0 && (str[i] == '#' || str[i] == '.') && str[i + 1] != '\0' && i != 0)
	{
		if (str[i + 1] != '\n' || str[i + 2] != '\n')
		{
			return (0);//\n apres tetri
		}
	}
	/*if (lines % 4 == 0 && hashtags != lines)
		return (0);//tetriminos vide*/
	if (hashtags % 4 != 0 && lines % 4 == 0 && characters % 4 == 0)//pas bon nombre de #
	{
		return (0);
	}
	if (/*hashtags % 4 <= 3 && hashtags % 4 != 0 && */str[i] == '#')
	{
		if (str[i + 1] != '#' && str[i + 5] != '#' && (i > 0 && str[i - 1] != '#') && (i >= 5 && str[i - 5] != '#'))
		{
			return (0);//# isole
		}
	}
	if (characters > 545)//trop de tetriminos
		return (0);
	if (str[i + 1] == '\0')
		if (characters % 4 != 0 || (str[i - 1] != '#' && str[i - 1] != '.') || str[i] != '\n' || hashtags != lines)
		{
			return (0);//mauvaise fin ou fichier d'un tetri vide
		}
	return (1);
}
// si deux tetri dans un seul ?
int		validite(char* enter)
{
	int		i;
	int		characters;
	int		lines;
	int		hashtags;

	i = 0;
	characters = 0;
	lines = 0;
	hashtags = 0;
	while (enter[i])
	{
		if (enter[i] == '#' || enter[i] == '.')
			characters++;
		if (characters % 4 == 0 && enter[i] != '\n')
		{
			lines++;
		}
		if (enter[i] == '#')
		{
			hashtags++;
		}
		if ((validite2(characters, lines, hashtags, &enter[i])) == 0)
			return (0);
		i++;
	}
	if (lines == 0 || demitetri(enter) == 0)
		return (0);// verifier
//	printf("hashtags = %d\n", hashtags);
//	printf("lines = %d\n", lines);
	return (1);
}
//
//
