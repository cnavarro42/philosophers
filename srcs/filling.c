/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:23:37 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/27 17:47:29 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	fill_dat(int argc, char **argv, t_datos *dat)
{
	pthread_mutex_t *fork_mutex;
	int i;

	i = 0;
	if (argc == 6)
		dat->eating_bool = 1;
	else
		dat->eating_bool = 0;
	dat->number_of_philo = ft_atoi(argv[1]);
	dat->time_to_die = (uint64_t)ft_atoi(argv[2]);
	dat->time_to_eat = (uint64_t)ft_atoi(argv[3]);
	dat->time_to_sleep = (uint64_t)ft_atoi(argv[4]);
	printf("eating_bool: %i\n", dat->eating_bool);
	if (dat->eating_bool)
		dat->times_eating = ft_atoi(argv[5]);
	dat->time_start = gettime();
	dat->is_dead = 0;
	dat->philo = malloc(sizeof(pthread_t) * dat->number_of_philo);
	dat->phil = malloc(sizeof(t_philo) * dat->number_of_philo);
	fork_mutex = malloc(sizeof(pthread_mutex_t) * dat->number_of_philo);
	while(i < dat->number_of_philo)
	{
		pthread_mutex_init(&fork_mutex[i], NULL);
		pthread_mutex_unlock(&fork_mutex[i]);
		i++;
	}
	dat->fork_mutex = fork_mutex;
}

void	fill_philo(t_datos *dat, t_philo *phil, int i)
{
	phil->is_dead = &dat->is_dead;
	phil->time_to_die = dat->time_to_die;
	phil->time_to_eat = dat->time_to_eat;
	phil->time_to_sleep = dat->time_to_sleep;
	phil->times_eating = dat->times_eating;
	phil->im_the = i;
	phil->time_start = dat->time_start;
	phil->eating_bool = dat->eating_bool;
	if (i == dat->number_of_philo - 1)
		phil->r_fork = dat->fork_mutex[0];
	else
		phil->r_fork = dat->fork_mutex[i + 1];
	phil->l_fork = dat->fork_mutex[i];
	printf("eeeeating_bool: %i\n", dat->eating_bool);
}
