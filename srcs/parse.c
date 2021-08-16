/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:08:14 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/12 13:24:55 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	arg_errors(int argc, char **argv)
{
	int i;
	int j;

	if (!(argc == 5 || argc == 6))
		ft_strerror("Number of arguments invalid", 1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				ft_strerror("Invalid argument: No numerical", 2);
			j++;
		}
		i++;
	}
}
