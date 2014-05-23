/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:36:36 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:36:41 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "libft/includes/libft.h"
# define X "PLAYER 1"
# define O "PLAYER 2"
typedef struct	s_pos
{
	int			i;
	int			j;
}				t_pos;

typedef struct	s_data
{
	char		**tab;
	int			line;
	int			column;
	t_pos		last;
	char		play;
	int			begin_player;
	char		*name;
}				t_data;

/*
* ft_check.c
*/

int				ft_check_win(t_data *d);
int				ft_check_horizontal(t_data d, char c);
int				ft_check_diag_right(t_data d, char c);
int				ft_check_diag_left(t_data d, char c);
int				ft_check_vertical(t_data d, char c);

/*
* ft_print.c
*/

void			ft_print_column(t_data d, int i, int j, int k);
void			ft_print_grille(t_data d);
int				ft_error(int nb);

/*
* ft_init.c
*/

int				ft_get_size(t_data *d, int ac, char **av);
void			ft_init(t_data *d);

/*
* ft_read.c
*/

void			ft_read(t_data *d);
int				ft_put_piece(t_data *d, int column);
int				ft_verif(t_data d, int column);

/*
* ft_ia.c
*/

void			ft_ia(t_data *d);
#endif /* ! PUISSANCE4_H*/
