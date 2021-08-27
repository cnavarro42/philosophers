/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:07:35 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/27 18:16:12 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define TRUE 1
# define FALSE 0
# include "../libft/libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_philo
{
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	int					times_eating;
	uint64_t			last_time_eating;
	int					eating_bool;
	int					im_the;
	uint64_t			time_start;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*printing;
	int					*is_dead;
}						t_philo;

typedef struct			s_datos
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
	pthread_mutex_t		*printing;
	int					is_dead;
}						t_datos;

void		*philo_routine(void *arg);
void		arg_errors(int argc, char **argv);
void		fill_philo(t_datos *dat, t_philo *phil, int i);
void		fill_dat(int argc, char **argv, t_datos *dat);
void		ft_usleep(uint64_t time);
uint64_t	gettime(void);
void		printf_choice(int num, t_philo *phil);
#endif
