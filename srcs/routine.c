/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:41 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/28 16:14:10 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void you_died(t_philo *phil)
{
	if	(*phil->is_dead == 0)
	{
		*phil->is_dead = 1;
		printf("[ %7llu ] Philosopher %i has died\n",
			gettime() - phil->time_start, phil->im_the);
	}
}

void eating(t_philo *phil)
{
	//printf("%llu//%llu", (gettime() - phil->last_time_eating), phil->time_to_die);
	if (phil->im_the % 2)
	{
		phil->has_problems = 1;
		pthread_mutex_lock(phil->l_fork);
		printf_choice(1, phil);
		if ((gettime() - phil->last_time_eating) > phil->time_to_die)
			you_died(phil);
		pthread_mutex_lock(phil->r_fork);
		phil->has_problems = 0;
		printf_choice(6, phil);
	}
	else
	{
		phil->has_problems = 1;
		pthread_mutex_lock(phil->r_fork);
		printf_choice(6, phil);
		if ((gettime() - phil->last_time_eating) > phil->time_to_die)
			you_died(phil);
		pthread_mutex_lock(phil->l_fork);
		phil->has_problems = 0;
		printf_choice(1, phil);
	}
	phil->last_time_eating = gettime();
	printf_choice(2, phil);
	ft_usleep(phil->time_to_eat);
	pthread_mutex_unlock(phil->l_fork);
	printf_choice(5, phil);
	pthread_mutex_unlock(phil->r_fork);
	printf_choice(7, phil);
}

void sleeping(t_philo *phil)
{
	printf_choice(3, phil);
	sleep_time(phil);
}

void thinking(t_philo *phil)
{
	printf_choice(4, phil);
}

void	*philo_routine(void *arg)
{
	t_philo *phil; 

	phil = (t_philo *)arg;
	phil->last_time_eating = phil->time_start;
	if (phil->eating_bool == 0)
		phil->times_eating = 1;
	while (*phil->is_dead == 0 && phil->times_eating > 0)
	{
		eating(phil);
		sleeping(phil);
		thinking(phil);
		if (phil->eating_bool == 1)
			phil->times_eating--;
	}
	return (NULL);
}
