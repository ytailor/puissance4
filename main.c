/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:36:23 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:36:24 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int				main(int ac, char **av)
{
	t_data		d;

	if (ac != 3)
		return (ft_error(1));
	if (ft_get_size(&d, ac, av) == -1)
		return (-1);
	ft_init(&d);
	if (!d.tab)
		return (-1);
	ft_print_grille(d);
	while (!ft_check_win(&d))
	{
		if (d.play == 'X')
		{
			ft_putendl("It's your turn !\n");
			ft_read(&d);
		}
		else
		{
			ft_ia(&d);
			ft_print_grille(d);
		}
	}
	return (0);
}
