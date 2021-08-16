/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:41 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/12 16:57:17 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void eating(t_philo *phil)
{
	//take_a_fork();
	pthread_mutex_lock(&phil->l_fork);
	pthread_mutex_lock(&phil->r_fork);
	printf("Philosofer %i is eating\n", phil->im_the);
	usleep(1000000);
	pthread_mutex_unlock(&phil->l_fork);
	pthread_mutex_unlock(&phil->r_fork);
	//release_a_fork();
}

void sleeping(t_philo *phil)
{
	printf("Philosofer %i is sleeping\n", phil->im_the);
	usleep(20000);
}

void thinking(t_philo *phil)
{
	printf("Philosofer %i is thinking\n", phil->im_the);
	usleep(100000);
}
void	*philo_routine(void *arg)
{
	t_philo *phil;
	phil = (t_philo *)arg;
	printf("Philosofer %i is thinking\n", phil->im_the);
	eating(phil);
	/*while (TRUE)
	{
		
		sleeping(phil);
		thinking(phil);
	}
	*/
	return (NULL);
}
