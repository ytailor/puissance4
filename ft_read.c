/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:36:15 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:53:04 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"


static int			ft_isdigitloop(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int					ft_put_piece(t_data *d, int column)
{
	int				i;

	i = d->line - 1;
	while (i >= 0)
	{
		if (d->tab[i][column] == 0 && !ft_verif(*d, column))
		{
			d->tab[i][column] = d->play;
			d->last.i = i;
			d->last.j = column;
			return (1) ;
		}
		i--;
	}
	return (0);
}

int					ft_verif(t_data d, int column)
{
	if (d.tab[0][column] == 0)
		return (0);
	return (1);
}

void				ft_read(t_data *d)
{
	char			*str;
	unsigned int	size;
	int				column;

	column = 0;
	str = NULL;
	size = ft_strlen(ft_itoa(d->column));
	while (ft_printf("Just Play : ") && get_next_line(0, &str) == 1)
	{
		if (!str)
			continue ;
		column = ft_atoi (str) - 1;
		if (!ft_isdigitloop(str) || column < 0 || ft_strlen(str) > size
				|| column >= d->column || ft_verif(*d, column))
			ft_putendl("Wrong parameter");
		else
		{
			ft_put_piece(d, column);
			ft_print_grille(*d);
			break ;
		}
		ft_strdel(&str);
	}
}
