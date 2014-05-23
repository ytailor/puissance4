/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:35:44 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:35:45 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int			ft_ia_def(t_data *d)
{
	int				i;
	int				j;

	i = -1;
	while (++i < d->line)
	{
		j = -1;
		while (++j < d->column)
		{
			d->last.i = i;
			d->last.j = j;
			if (!d->tab[i][j])
			{
				if (ft_check_horizontal(*d, 'X') >= 2 ||
					ft_check_diag_left(*d, 'X') >= 3 ||
					ft_check_diag_right(*d, 'X') >= 3 ||
					ft_check_vertical(*d, 'X') >= 3)
				{
					ft_put_piece(d, j);
					return (1);
				}
			}
		}
	}
	return (0);
}

static int			ft_ia_attack(t_data *d, int p, int p2)
{
	int				i;
	int				j;

	i = -1;
	while (++i < d->line)
	{
		j = -1;
		while (++j < d->column)
		{
			d->last.i = i;
			d->last.j = j;
			if (!d->tab[i][j])
			{
				if (ft_check_horizontal(*d, 'O') >= p ||
						ft_check_diag_left(*d, 'O') >= p2 ||
						ft_check_diag_right(*d, 'O') >= p2 ||
						ft_check_vertical(*d, 'O') >= p)
				{
					ft_put_piece(d, j);
					return (1);
				}
			}
		}
	}
	return (0);
}

void				ft_ia(t_data *d)
{
	int				j;

	j = 0;
	if (!ft_ia_attack(d, 3, 3))
	{
		if (!ft_ia_def(d))
		{
			if (!ft_ia_attack(d, 2, 1))
			{
				while (!j)
					j = ft_put_piece(d, rand() % d->column);
			}
		}
	}
}
