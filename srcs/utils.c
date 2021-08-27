/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:44:55 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/27 18:17:10 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

uint64_t gettime(void)
{
	struct timeval time;
	uint64_t mseconds;

	gettimeofday(&time, NULL);
	mseconds = (uint64_t)((time.tv_sec * 1000) + (time.tv_usec / 1000));

	return (mseconds);
}

void	ft_usleep(uint64_t time)
{
	uint64_t	finish;

	finish = gettime() + time;
	while (gettime() < finish)
		usleep(1);
}

void	printf_choice(int num, t_philo *phil)
{
	pthread_mutex_lock(phil->printing);
	if (num == 1)
		printf("[ %7llu ] Philosopher %i has died\n",
			gettime() - phil->time_start, phil->im_the);
	else if (num == 2)
		printf("[ %7llu ] Philosopher %i is eating\n",
			phil->last_time_eating - phil->time_start, phil->im_the);
	else if (num == 3)
		printf("[ %7llu ] Philosopher %i is sleeping\n",
			gettime() - phil->time_start, phil->im_the);
	else if (num == 4)
		printf("[ %7llu ] Philosopher %i is thinking\n",
			gettime() - phil->time_start, phil->im_the);
	else
		printf("Bad number");
	pthread_mutex_unlock(phil->printing);
}
