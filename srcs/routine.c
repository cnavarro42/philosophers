/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:41 by cnavarro          #+#    #+#             */
/*   Updated: 2021/09/02 12:23:06 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	you_died(t_philo *phil)
{
	if (*phil->is_dead == 0)
	{
		*phil->is_dead = 1;
		pthread_mutex_lock(phil->timeget);
		printf("[ %7llu ] Philosopher %i has died\n",
			gettime() - phil->time_start, phil->im_the);
		pthread_mutex_unlock(phil->timeget);
		pthread_mutex_unlock(phil->l_fork);
		pthread_mutex_unlock(phil->r_fork);
	}
}

static void	eating2(t_philo *phil)
{
	pthread_mutex_lock(phil->eat_or_die);
	pthread_mutex_lock(phil->timeget);
	phil->last_time_eating = gettime();
	pthread_mutex_unlock(phil->timeget);
	printf_choice(2, phil);
	pthread_mutex_unlock(phil->eat_or_die);
	ft_usleep(phil->time_to_eat, phil);
	pthread_mutex_unlock(phil->l_fork);
	printf_choice(5, phil);
	pthread_mutex_unlock(phil->r_fork);
	printf_choice(7, phil);
}

static void	eating(t_philo *phil)
{
	if (phil->im_the % 2)
	{
		phil->has_problems = 1;
		pthread_mutex_lock(phil->l_fork);
		printf_choice(1, phil);
		pthread_mutex_lock(phil->r_fork);
		phil->has_problems = 0;
		printf_choice(6, phil);
	}
	else
	{
		phil->has_problems = 1;
		pthread_mutex_lock(phil->r_fork);
		printf_choice(6, phil);
		pthread_mutex_lock(phil->l_fork);
		phil->has_problems = 0;
		printf_choice(1, phil);
	}
	eating2(phil);
}

static void	sleeping(t_philo *phil)
{
	printf_choice(3, phil);
	sleep_time(phil);
}

void	*philo_routine(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;
	phil->last_time_eating = phil->time_start;
	while (*phil->is_dead == 0 && phil->times_eating > 0)
	{
		eating(phil);
		sleeping(phil);
		printf_choice(4, phil);
		if (phil->eating_bool == 1)
			phil->times_eating--;
	}
	return (NULL);
}
