/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:07:35 by cnavarro          #+#    #+#             */
/*   Updated: 2021/09/07 16:02:57 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define TRUE 1
# define FALSE 0
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	int					times_eating;
	uint64_t			last_time_eating;
	int					eating_bool;
	int					im_the;
	int					number_of_philo;
	uint64_t			time_start;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*printing;
	pthread_mutex_t		*eat_or_die;
	pthread_mutex_t		*timeget;
	int					*is_dead;
	int					*magic;
	int					has_problems;
}				t_philo;

typedef struct s_datos
{
	int					number_of_philo;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	int					times_eating;
	int					eating_bool;
	uint64_t			time_start;
	t_philo				*phil;
	pthread_t			*philo;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		printing;
	pthread_mutex_t		eat_or_die;
	pthread_mutex_t		timeget;
	int					is_dead;
	int					magic;
}				t_datos;

void		*philo_routine(void *arg);
int			arg_errors(int argc, char **argv);
void		fill_philo(t_datos *dat, t_philo *phil, int i);
void		fill_dat(int argc, char **argv, t_datos *dat);
void		ft_usleep(uint64_t time, t_philo *phil);
uint64_t	gettime(void);
void		printf_choice(int num, t_philo *phil);
void		sleep_time(t_philo *phil);
void		you_died(t_philo *phil);
void		*ft_calloc(size_t n, size_t s);
void		ft_bzero(void *str, size_t n);
int			ft_atoi(const char *str);
int			ft_isdigit(int i);
#endif
