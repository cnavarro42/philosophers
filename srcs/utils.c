/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:44:55 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/31 16:19:27 by cnavarro         ###   ########.fr       */
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

void	ft_usleep(uint64_t time, t_philo *phil)
{
	uint64_t	finish;
	uint64_t	getaux;

	pthread_mutex_lock(phil->timeget);
	finish = gettime() + time;
	getaux = gettime();
	pthread_mutex_unlock(phil->timeget);
	while (getaux < finish)
	{
		pthread_mutex_lock(phil->timeget);
		getaux = gettime();
		pthread_mutex_unlock(phil->timeget);
		usleep(phil->number_of_philo);
	}
}

static void	printf_choice2(int num, t_philo *phil)
{
	if 	(num == 5)
		printf("[ %7llu ] Philosopher %i release the left fork\n",
			gettime() - phil->time_start, phil->im_the);
	else if (num == 6)
		printf("[ %7llu ] Philosopher %i take the right fork\n",
			gettime() - phil->time_start, phil->im_the);
	else if (num == 7)
		printf("[ %7llu ] Philosopher %i release the right fork\n",
			gettime() - phil->time_start, phil->im_the);
	else
		printf("Bad number");
}

void	printf_choice(int num, t_philo *phil)
{
	if	(*phil->is_dead == 0)
	{
		pthread_mutex_lock(phil->printing);
		if (num == 1)
			printf("[ %7llu ] Philosopher %i take the left fork\n",
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
			printf_choice2(num, phil);
		pthread_mutex_unlock(phil->printing);
	}
}

void	sleep_time(t_philo *phil)
{
	uint64_t	time_elapsed;
	pthread_mutex_lock(phil->timeget);
	time_elapsed = (gettime() - phil->last_time_eating);
	pthread_mutex_unlock(phil->timeget);
	if ((time_elapsed + phil->time_to_sleep) > phil->time_to_die)
	{
		ft_usleep(phil->time_to_die - time_elapsed, phil);
		you_died(phil);
	}
	else
		ft_usleep(phil->time_to_sleep, phil);
}
