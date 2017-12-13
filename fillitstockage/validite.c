/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:49:34 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/01 23:47:04 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		validite(int characters, int lines, int hashtags, char *str)
{
	int		i;

	i = 0;
	if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
		return (0);
	if (str[i] == '\n')
	{
		if (str[i + 1] == '\n' || characters == 0)
		{
			if (str[i + 2] == '\n' || characters % 4 != 0 || characters == 0)
				return (0);
		}
	}
	if (characters % 4 == 0 && str[i] != '\n')
	{
		if (str[i + 1] != '\n')
			return (0);
	}
	if (lines % 4 == 0 && (str[i] == '#' || str[i] == '.') && str[i + 1] != '\0' && i != 0)
	{
		if (str[i + 1] != '\n' || str[i + 2] != '\n')
		{
			return (0);
		}
	}
	if (hashtags % 4 != 0 && lines % 4 == 0 && characters % 4 == 0)
	{
		return (0);
	}
	if (hashtags % 4 <= 3 && hashtags % 4 != 0 && str[i] == '#')
		if (str[i + 1] != '#' && str[i + 5] != '#')
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

#include <stdlib.h>
int		defilement(char* enter)
{
	int		i;
	int		characters;
	int		lines;
	int		hashtags;
//	int		*tab;

	i = 0;
	characters = 0;
	lines = 0;
	hashtags = 0;
//	tab = (int*)malloc(sizeof(int) * 4);
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
		if ((validite(characters, lines, hashtags, &enter[i])) == 0)
			return (0);
		i++;
	}
//	tab[0] = i;
//	tab[1] = characters;
//	tab[2] = lines;
//	tab[3] = hashtags;
	return (1);
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int		main(int argc, char **argv)
{
	int		fd;
	char	tmp[1024];
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	read(fd, tmp, 545);
	printf("%d\n", defilement(tmp));
//	printf("i = %d\n", defilement(tmp)[0]);
//	printf("characters = %d\n", defilement(tmp)[1]);
//	printf("lines = %d\n", defilement(tmp)[2]);
//	printf("hashtags = %d\n", defilement(tmp)[3]);
	return (0);
}
