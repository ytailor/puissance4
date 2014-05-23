/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:35:33 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:35:34 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int			ft_check_vertical(t_data d, char player)
{
	int		i;
	int		j;
	int		count;

	i = d.last.i;
	j = d.last.j;
	count = 0;
	while (i >= 0)
	{
		if (i - 1 >= 0 && d.tab[i - 1][j] == player)
			count++;
		else
			break ;
		i--;
	}
	i = d.last.i;
	while (i <= d.line - 1)
	{
		if (i + 1 <= d.line - 1 && d.tab[i + 1][j] == player)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

int			ft_check_diag_left(t_data d, char player)
{
	t_pos	pos;
	int		count;

	pos.i = d.last.i;
	pos.j = d.last.j;
	count = 0;
	while (pos.i >= 0 && pos.j >= 0)
	{
		if (pos.i - 1 >= 0 && pos.j - 1 >= 0 &&
				d.tab[pos.i-- - 1][pos.j-- - 1] == player)
			count++;
		else
			break ;
	}
	pos.i = d.last.i;
	pos.j = d.last.j;
	while (pos.i <= d.line - 1 && pos.j <= d.column - 1)
	{
		if (pos.i + 1 <= d.line - 1 && pos.j + 1 <= d.column - 1
				&& d.tab[pos.i++ + 1][pos.j++ + 1] == player)
			count++;
		else
			break ;
	}
	return (count);
}

int			ft_check_diag_right(t_data d, char player)
{
	t_pos	pos;
	int		count;

	pos.i = d.last.i;
	pos.j = d.last.j;
	count = 0;
	while (pos.i >= 0 && pos.j <= d.column - 1)
	{
		if (pos.i - 1 >= 0 && pos.j + 1 <= d.column - 1
				&& d.tab[pos.i-- - 1][pos.j++ + 1] == player)
			count++;
		else
			break ;
	}
	pos.i = d.last.i;
	pos.j = d.last.j;
	while (pos.i <= d.line - 1 && pos.j >= 0)
	{
		if (pos.i + 1 <= d.line - 1 && pos.j - 1 >= 0
				&& d.tab[pos.i++ + 1][pos.j-- - 1] == player)
			count++;
		else
			break ;
	}
	return (count);
}

int			ft_check_horizontal(t_data d, char player)
{
	int		i;
	int		j;
	int		count;

	i = d.last.i;
	j = d.last.j;
	count = 0;
	while (j >= 0 && j <= d.column - 1)
	{
		if (j - 1 >= 0 && d.tab[i][j - 1] == player)
			count++;
		else
			break ;
		j--;
	}
	j = d.last.j;
	while (j >= 0 && j <= d.column - 1)
	{
		if (j + 1 <= d.column - 1 && d.tab[i][j + 1] == player)
			count++;
		else
			break ;
		j++;
	}
	return (count);
}

int			ft_check_win(t_data *d)
{
	if (ft_check_vertical(*d, d->play) >= 3 ||
		ft_check_horizontal(*d, d->play) >= 3 ||
		ft_check_diag_left(*d, d->play) >= 3 ||
		ft_check_diag_right(*d, d->play) >= 3)
	{
		if (d->play == 'X')
			ft_printf("%s WINNN !\n", d->name);
		else
			ft_putendl("Computer WINNNN !");
		return (1);
	}
	d->play = (d->play == 'X') ? 'O' : 'X';
	return (0);
}
