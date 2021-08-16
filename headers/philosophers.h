/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:07:35 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/12 16:25:28 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define TRUE 1
# define FALSE 0
# include "../libft/libft.h"
# include <pthread.h>
# include <sys/time.h>



typedef struct	s_philo
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_eating;
	int	im_the;
	pthread_mutex_t r_fork;
	pthread_mutex_t l_fork;
}				t_philo;

typedef struct	s_datos
{
	int			number_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_eating;
	int			eating_bool;
	t_philo		*phil;
	pthread_t	*philo;
	pthread_mutex_t *fork_mutex;
}				t_datos;
void	*philo_routine(void *arg);
void	arg_errors(int argc, char **argv);
void	fill_philo(t_datos *dat, t_philo *phil, int i);
void	fill_dat(int argc, char **argv, t_datos *dat);
#endif
