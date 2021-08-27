/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:41 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/27 17:59:24 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void you_died(t_philo *phil)
{
	*phil->is_dead = 1;
	printf_choice(1, phil);
}

void eating(t_philo *phil)
{
	if ((gettime() - phil->last_time_eating) > phil->time_to_die)
		you_died(phil);
	if (phil->im_the % 2)
	{
		pthread_mutex_lock(&phil->l_fork);
		pthread_mutex_lock(&phil->r_fork);
	}
	else
	{
		pthread_mutex_lock(&phil->r_fork);
		pthread_mutex_lock(&phil->l_fork);
	}
	if ((gettime() - phil->last_time_eating) > phil->time_to_die)
		you_died(phil);
	phil->last_time_eating = gettime();
	printf_choice(2, phil);
	ft_usleep(phil->time_to_eat);
	pthread_mutex_unlock(&phil->l_fork);
	pthread_mutex_unlock(&phil->r_fork);
}

void sleeping(t_philo *phil)
{
	printf_choice(3, phil);
	ft_usleep(phil->time_to_sleep);
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
