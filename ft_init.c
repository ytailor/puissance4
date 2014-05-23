/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:35:53 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/09 21:41:11 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int				ft_get_size(t_data *d, int ac, char **av)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (++i < 3)
		{
			while (av[i][j] && ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] != '\0')
				return (ft_error(2));
		}
		d->line = ft_atoi(av[1]);
		d->column = ft_atoi(av[2]);
		if (d->line < 6 || d->column < 7)
			return (ft_error(2));
	}
	return (0);
}

void			ft_init(t_data *d)
{
	int			i;
	int			j;
	char		*str;

	str = NULL;
	i = -1;
	j = -1;
	if (!(d->tab = (char **)malloc(sizeof(char *) * (d->line + 1))))
		return ;
	while (++i < d->line)
		d->tab[i] = (char *)malloc(sizeof(char) * (d->column + 1));
	i = -1;
	while (++i < d->line)
	{
		j = -1;
		while (++j < d->column)
			d->tab[i][j] = 0;
	}
	srand(time(NULL));
	d->begin_player = rand() % 2 + 1;
	d->play = (d->begin_player == 1) ? 'O' : 'X';
	ft_printf("Type your name : ");
	if (get_next_line(0, &str) == 1)
		d->name = str;
	ft_printf("\033[33m%s\033[0m you are : \033[33m%c\033[0m\n", d->name, 'X');
}
