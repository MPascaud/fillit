/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:05:04 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/15 19:17:07 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	tmp[1024];
	int		tetris;
	t_list	*liste;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <input_file>\0");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error : no open file\n");
		return (0);
	}
	read(fd, tmp, 545);
	if(!(*tmp) || validite(tmp) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	printf("validite : %d\n", validite(tmp));
/*	liste = (construction(tmp));
	liste = liste->next;
	tetris = nombretetris(tmp);
	ft_putstr(dimensionnement(tetris, liste));*/
	return (0);
}
