/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:08:14 by cnavarro          #+#    #+#             */
/*   Updated: 2021/09/02 12:10:53 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static int	arg_errors3(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				perror("Invalid argument: No numerical");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_errors2(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
	{
		perror("Number of arguments invalid");
		return (1);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		perror("This is too much");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) > 1000)
	{
		perror("This is too much");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		perror("No philosophers");
		return (1);
	}
	return (0);
}

int	arg_errors(int argc, char **argv)
{
	int	i;

	if (arg_errors2(argc, argv))
		return (1);
	if (arg_errors3(argv))
		return (1);
	i = 2;
	while (i < 5)
	{
		if (ft_atoi(argv[i]) > 10000)
		{
			perror("This is too much");
			return (1);
		}
		i++;
	}
	return (0);
}
