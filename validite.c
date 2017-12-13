/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:49:34 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/12 15:52:04 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

static int		validite2(int characters, int lines, int hashtags, char *str)
{
	int		i;

	i = 0;
	if (str[i] != '#' && str[i] != '.' && str[i] != '\n')//mauvais signes
		return (0);
	if (str[i] == '\n')
	{
		if (str[i + 1] == '\n' || characters == 0)
		{
			if (str[i + 2] == '\n' || characters % 4 != 0 || characters == 0)//trop de \n, ou pas bon nombre de #
				return (0);
		}
	}
	if (characters % 4 == 0 && str[i] != '\n')
	{
		if (str[i + 1] != '\n')//pas de \0 ?
			return (0);
	}
	if (lines % 4 == 0 && (str[i] == '#' || str[i] == '.') && str[i + 1] != '\0' && i != 0)
	{
		if (str[i + 1] != '\n' || str[i + 2] != '\n')
		{
			return (0);//\n apres tetri
		}
	}
	if (hashtags % 4 != 0 && lines % 4 == 0 && characters % 4 == 0)//pas bon nombre de #
	{
		return (0);
	}
	if (hashtags % 4 <= 3 && hashtags % 4 != 0 && str[i] == '#')
		if (str[i + 1] != '#' && str[i + 5] != '#' && (i > 0 && str[i - 1] != '#') && (i >= 5 && str[i - 5] != '#'))
		{
			return (0);
		}
	if (characters > 545)
		return (0);
	if (str[i + 1] == '\0')
		if (characters % 4 != 0 || (str[i - 1] != '#' && str[i - 1] != '.') || str[i] != '\n')
		{
			return (0);
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
	return (1);
}
