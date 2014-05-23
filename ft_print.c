/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:36:04 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:39:31 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void			ft_print_grille(t_data d)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < d.line)
	{
		j = -1;
		k = 0;
		ft_print_column(d, i, j, k);
		ft_putendl("");
	}
	k = 0;
	while (++k <= d.column)
		ft_putstr("\033[34m ----- \033[0m");
	j = 0;
	ft_putendl("");
	while (++j <= d.column)
	{
		if (j <= 9)
			ft_printf("   \033[1m%d\033[0m   ", j);
		else
			ft_printf("   %d  ", j);
	}
	ft_putendl("\n");
}

void			ft_print_column(t_data d, int i, int j, int k)
{
	while (++k <= d.column)
		ft_putstr("\033[34m ----- \033[0m");
	ft_putchar('\n');
	while (++j < d.column)
	{
		ft_putstr("\033[34m|  \033[0m");
		if (d.tab[i][j])
		{
			if (d.tab[i][j] == 'X')
				ft_printf("\033[33m◉\033[0m");
			else
				ft_printf("\033[31m◉\033[0m");
		}
		else
			ft_putchar(' ');
		ft_putstr("   ");
	}
	ft_putstr("\033[34m|  \033[0m");
}

int				ft_error(int nb)
{
	if (nb == 1)
		ft_putendl_fd("Usage : ./puissance4 [line] [column]", 2);
	if (nb == 2)
		ft_putendl_fd("Error : invalide grid size", 2);
	return (-1);
}
