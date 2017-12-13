/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:37:31 by mpascaud          #+#    #+#             */
/*   Updated: 2017/12/13 11:48:23 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_H
# define TETRI_H

#include <stdio.h>

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct		s_list
{
	int				position;
	int				x[4];
	int				y[4];
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					validite(char *enter);
t_list				*construction(char *enter);
void				afficherliste(t_list **liste);
char				*carredepart(char *tmp);
t_list				*ft_lstnew(int *x, int *y, int position, t_list *maillon);
int					placelibre(t_list *maillon, char *carre);
void				placement(t_list *maillon, char *carre);
void				backdot(t_list *maillon, char *carre);
char				*agencement(t_list *liste, char *carre);
char				*dimensionnement(int tetris, t_list *liste);
int					nombretetris(char *tmp);
char				*dimensions(int tetriminos);

#endif
