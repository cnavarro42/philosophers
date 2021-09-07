/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:35:29 by cnavarro          #+#    #+#             */
/*   Updated: 2021/09/07 13:54:24 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static void	flying_free(t_datos *dat)
{
	free(dat->phil);
	free(dat->philo);
	free(dat->fork_mutex);
}

static void	grader(t_datos *dat)
{
	int	i;

	i = 0;
	while (i < dat->number_of_philo)
	{
		fill_philo(dat, &dat->phil[i], i);
		if (0 != pthread_create(&dat->philo[i], NULL
				, philo_routine, &dat->phil[i]))
			printf("Hilo no creado correctamente");
		i++;
	}
}

static void	waiting_room(t_datos *dat)
{
	int	i;

	i = 0;
	while (i < dat->number_of_philo)
	{
		pthread_join(dat->philo[i], NULL);
		i++;
	}
}

static void	voyeur_bucle(t_datos *dat)
{
	int	i;
	int	philos;

	philos = dat->number_of_philo;
	i = 0;
	while (dat->is_dead == 0 && dat->phil[i].times_eating > 0)
	{
		if (dat->phil[i].has_problems == 1)
		{
			pthread_mutex_lock(&dat->eat_or_die);
			pthread_mutex_lock(&dat->timeget);
			if ((gettime() - dat->phil[i].last_time_eating) > dat->time_to_die)
			{
				pthread_mutex_unlock(&dat->timeget);
				you_died(&dat->phil[i]);
			}
			pthread_mutex_unlock(&dat->timeget);
		}
		pthread_mutex_unlock(&dat->eat_or_die);
		i++;
		if (i >= (philos))
			i = 0;
		usleep(1);
	}
}

int	main(int argc, char **argv)
{
	t_datos	*dat;

	dat = ft_calloc(sizeof(t_datos), 1);
	if (arg_errors(argc, argv))
		return (-1);
	fill_dat(argc, argv, dat);
	grader(dat);
	voyeur_bucle(dat);
	waiting_room(dat);
	flying_free(dat);
	return (0);
}
